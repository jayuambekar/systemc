#pragma once

#include <systemc>
#include "tlm.h"

class Initiator : public sc_core::sc_module, tlm::tlm_bw_nonblocking_transport_if<>
{
public:
	tlm::tlm_initiator_socket<> init_socket;
	Initiator(sc_core::sc_module_name module_name);

private:


};
