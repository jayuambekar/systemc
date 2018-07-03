#include <Initiator.h>

using namespace sc_core;
using namespace tlm;

Initiator :: Initiator(sc_module_name module_name)
	: sc_module(module_name)
	, init_socket("init_socket")
	, dmi_ptr(NULL)
{
	read_dly = sc_time(5, SC_NS);
	write_dly = sc_time(4, SC_NS);

	read_buff = new unsigned char[BUFF_SIZE];
	write_buff = new unsigned char[BUFF_SIZE];

	read_file((char *)"1mb.bin",write_buff,BUFF_SIZE);

	init_socket.bind(*this);

	SC_THREAD(read_write);

}

Initiator :: ~Initiator()
{
	delete[] read_buff;
	delete[] write_buff;
}

void  Initiator :: read_mem()
{
	tlm_generic_payload trans;
	trans.set_command(TLM_READ_COMMAND);
	trans.set_data_length(4);
	trans.set_streaming_width(4);
	trans.set_byte_enable_ptr(0);
	trans.set_dmi_allowed(false);
	trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

	for(int i = 0 ; i < BUFF_SIZE; i+=4)
	{
		//int word = i;
		trans.set_address(uint64(i));
		trans.set_data_ptr(&read_buff[i]);

		init_socket->b_transport(trans, write_dly);

		if(trans.is_response_error())
		{
			SC_REPORT_ERROR("[TLM-2]",trans.get_response_string().c_str());
		}

		wait(read_dly);


			cout << "[READ_T][ " << sc_time_stamp() << " ] MEM[ " << i << " ] : " << (unsigned int)read_buff[i] << endl;


	}

}

void Initiator :: write_mem()
{
	tlm_generic_payload trans;
	trans.set_command(TLM_WRITE_COMMAND);
	trans.set_data_length(4);
	trans.set_streaming_width(4);
	trans.set_byte_enable_ptr(0);
	trans.set_dmi_allowed(false);
	trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

	tlm_dmi dmi_data;
	for(int i = 0; i < BUFF_SIZE; i+=4)
	{
		if(dmi_ptr != NULL && (dmi_start_address <= (uint64_t)i) && ((uint64_t)i <= dmi_end_address - 4)){
			memcpy(&dmi_ptr[i-dmi_start_address],&write_buff[i],4);
		}
		else{
			trans.set_address(uint64(i));
			trans.set_data_ptr(&write_buff[i]);
			init_socket-> b_transport(trans, write_dly);

			if(trans.is_response_error())
			{
				SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
			}
			wait(write_dly);

			cout << "[WRITE_T][ " << sc_time_stamp() << " ] MEM[ " << i << " ] : " << (unsigned int)write_buff[i] << endl;

			if(trans.is_dmi_allowed()){
				std::cout << "DMI is allowed " << std::endl;
				if(init_socket->get_direct_mem_ptr(trans, dmi_data)){
					std::cout << "Got DMI pointer " << std::endl;
					dmi_ptr = dmi_data.get_dmi_ptr();
					dmi_start_address = dmi_data.get_start_address();
					dmi_end_address = dmi_data.get_end_address();
				}
			}
		}
	}

}

bool Initiator::compare(const unsigned char* read_buff, const unsigned char* write_buff, size_t len)
{
	for(size_t i = 0 ; i < len; i++){
		if(read_buff[i] != write_buff[i]){
			return false;
		}
	}
	return true;
}

void Initiator::read_write()
{
	wait(1, SC_NS);
	write_mem();

	wait(1, SC_NS);
	read_mem();

	// Compare read and write buffer
	cout << "Test Result: " << (compare(read_buff, write_buff, BUFF_SIZE) ? "Passed" : "Failed") << endl;
}


size_t Initiator::read_file(char *fname, void *buf, size_t len)
{
	size_t r_len = 0;
	if (FILE *fp = fopen(fname, "r"))
	{
		r_len = fread(buf, 1, len , fp);
		fclose(fp);
	}
	else{
		SC_REPORT_ERROR("Initiator","Unable to open file");
	}
	return r_len;
}


tlm_sync_enum Initiator :: nb_transport_bw(tlm::tlm_generic_payload& trans,tlm::tlm_phase& phase,sc_core::sc_time& t)
{
	return tlm::TLM_COMPLETED;
}

void Initiator :: invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{
	dmi_ptr = NULL;
	return;
}
