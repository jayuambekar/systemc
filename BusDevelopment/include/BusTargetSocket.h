#pragma once

#include <systemc>
#include <tlm_utils/simple_target_socket.h>

class BusTargetSocket : public sc_core::sc_module
{
public:
	tlm_utils::simple_target_socket<BusTargetSocket> bus_target_socket;

	BusTargetSocket(sc_core::sc_module_name moduleName);
	SC_HAS_PROCESS(BusTargetSocket);

private:
	unsigned char *busTargetMemory;

	void b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time& delay);

};
