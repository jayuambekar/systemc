#pragma once

#include <systemc>
#include "tlm.h"

using namespace std;
using namespace tlm;
using namespace sc_dt;
using namespace sc_core;

#define BUFF_SIZE 1048576 //

class Initiator : public sc_core::sc_module, tlm::tlm_bw_nonblocking_transport_if<>
{
public:
	tlm_initiator_socket<> init_socket;

	Initiator(sc_core::sc_module_name module_name);

	SC_HAS_PROCESS(Initiator);

private:
	sc_time read_dly;
	sc_time write_dly;
	void read_mem();
	void write_mem();


};
