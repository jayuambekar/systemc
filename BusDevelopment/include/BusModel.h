#pragma once

#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>

class BusInitiatorSocket : public sc_core::sc_module
{
public:
	tlm_utils::simple_initiator_socket<BusInitiatorSocket> bus_init_socket;

	BusInitiatorSocket(sc_core::sc_module_name moduleName);
	SC_HAS_PROCESS(BusInitiatorSocket);

private:

};
