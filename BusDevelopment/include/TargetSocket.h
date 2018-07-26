#pragma once

#include <systemc>
#include <tlm_utils/simple_target_socket.h>

class TargetSocket : public sc_core::sc_module
{
public:
	tlm_utils::simple_target_socket<TargetSocket> target_socket;

	TargetSocket(sc_core::sc_module_name moduleName);
	SC_HAS_PROCESS(TargetSocket);

private:
	unsigned char *targetMemory;

	void b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time& delay);

};
