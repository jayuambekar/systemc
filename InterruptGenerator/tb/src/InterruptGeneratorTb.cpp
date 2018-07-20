#include <InterruptGeneratorTb.h>

InterruptGeneratorTb :: InterruptGeneratorTb(sc_core::sc_module_name module_name):
		sc_module(module_name)
	   ,initiatorSocket("initiatorSocket")
	   ,interruptsIn("interruptsIn", 10)
	   ,numInterrupts(10)
	   ,interruptRegisters(10)
{
	//initiatorSocket.bind(*this);
	SC_THREAD(read_write_interrupt);

	SC_THREAD(test);

	SC_METHOD(monitor);

}

void InterruptGeneratorTb ::read_write_interrupt()
{
	wait(1, sc_core::SC_NS);
	write_Interrupt();
	std::cout << "[ " << sc_core::sc_time_stamp() << " ] " << " write_interrupt"  << std::endl;

	wait(1, sc_core::SC_NS);
	read_Interrupt();
	std::cout << "[ " << sc_core::sc_time_stamp() << " ] " << " read_interrupt " << std::endl;
}

void InterruptGeneratorTb :: read_Interrupt()
{
	tlm::tlm_generic_payload trans;
	sc_core::sc_time delay = sc_core::SC_ZERO_TIME;

	trans.set_command(tlm::TLM_READ_COMMAND);
	trans.set_data_length(4);
	trans.set_streaming_width(4);
	trans.set_byte_enable_ptr(0);
	trans.set_dmi_allowed(false);
	trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

	for (int i = 0; i < 100; i += 4)
	{
		int word = i;
		trans.set_address(i);
		trans.set_data_ptr((unsigned char*)(word));

		initiatorSocket->b_transport(trans, delay);

		if (trans.is_response_error()) {
			SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
		}
	}
}

void InterruptGeneratorTb :: write_Interrupt()
{
	tlm::tlm_generic_payload trans;
	sc_core::sc_time delay = sc_core::SC_ZERO_TIME;

	trans.set_command(tlm::TLM_WRITE_COMMAND);
	trans.set_data_length(4);
	trans.set_streaming_width(4);
	trans.set_byte_enable_ptr(0);
	trans.set_dmi_allowed(false);
	trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

	for (int i = 0; i < 100; i += 4)
	{
		int word = i;
		trans.set_address(i);
		trans.set_data_ptr((unsigned char*) (word));
		initiatorSocket->b_transport(trans, delay);

		if (trans.is_response_error())
		{
			SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
		}
	}
}

void InterruptGeneratorTb :: test()
{
	wait(1, sc_core::SC_NS);

	for(int i=0; i<10; i++)
	{
		interruptsIn[i];

		std::cout << "[ " << sc_core::sc_time_stamp() << " ] " << " interrupt "<< i << std::endl;
	}

	wait(10, sc_core::SC_NS);
}

void InterruptGeneratorTb :: monitor()
{
	std::cout << "[ " << sc_core::sc_time_stamp() << " ] Interrupt asserted : Intr0 " << std::endl;
}

