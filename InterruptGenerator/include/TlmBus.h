#pragma once

#include <systemc>
#include <tlm_utils/simple_target_socket.h>
#include <tlm_utils/simple_initiator_socket.h>

class TlmBus : public sc_core::sc_module
{
public:
	tlm_utils::simple_target_socket<TlmBus> busTargetSocket;
	sc_core::sc_vector<tlm_utils::simple_initiator_socket<TlmBus>> busInitSocket;

	TlmBus(sc_core::sc_module_name moduleName, size_t noOfInitSocket);

private:
	SC_HAS_PROCESS(TlmBus);
	void b_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay);
};
