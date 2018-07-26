#include "InitiatorSocket.h"

InitiatorSocket :: InitiatorSocket(sc_core::sc_module_name moduleName)
				: sc_module(moduleName)
				, init_socket("init_socket")
{
	SC_THREAD(test_initiatorSocket);
}

void InitiatorSocket :: test_initiatorSocket()
{
	wait(10, sc_core::SC_NS);
	read_initiatorSocket();
}

void InitiatorSocket::read_initiatorSocket()
{
	tlm::tlm_generic_payload trans;
	sc_core::sc_time delay = sc_core::sc_time(10, sc_core::SC_NS);

	uint32_t value;
	trans.set_command(tlm::TLM_READ_COMMAND);
	trans.set_address(4);
	trans.set_data_ptr((unsigned char *) (&value));
	trans.set_streaming_width(4);
	trans.set_data_length(4);
	trans.set_dmi_allowed(false);
	trans.set_byte_enable_ptr(0);
	trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

	init_socket->b_transport(trans, delay);

	if (trans.is_response_error()) {
		SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
	}
}
