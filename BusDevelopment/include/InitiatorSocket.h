#pragma once

#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>

class InitiatorSocket : public sc_core::sc_module
{
public:
	tlm_utils::simple_initiator_socket<InitiatorSocket> init_socket;

	InitiatorSocket(sc_core::sc_module_name moduleName);

	SC_HAS_PROCESS(InitiatorSocket);

private:
	void test_initiatorSocket();
	void read_initiatorSocket();

};
