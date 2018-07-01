#include <Initiator.h>

using namespace sc_core;
using namespace tlm;

Initiator :: Initiator(sc_module_name module_name)
	: sc_module(module_name)
	, init_socket("init_socket")
{
	read_dly = sc_time(5, SC_NS);
	write_dly = sc_time(4, SC_NS);

	init_socket.bind(*this);

	SC_THREAD(read_mem);
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
		int word = i;
		trans.set_address(uint64(i));
		trans.set_data_ptr((unsigned char *)(&word));

		init_socket->b_transport(trans, write_dly);

		if(trans.is_response_error())
		{
			SC_REPORT_ERROR("[TLM-2]",trans.get_response_string().c_str());
		}

		wait(read_dly);
	}
}


tlm_sync_enum Initiator :: nb_transport_bw(tlm::tlm_generic_payload& trans,tlm::tlm_phase& phase,sc_core::sc_time& t)
{
	return tlm::TLM_COMPLETED;
}

void Initiator :: invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range)
{
	return;
}
