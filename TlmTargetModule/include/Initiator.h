#pragma once

#include <systemc>
#include "tlm.h"

using namespace std;
using namespace tlm;
using namespace sc_dt;
using namespace sc_core;

#define BUFF_SIZE 100

class Initiator : public sc_core::sc_module, tlm::tlm_bw_transport_if<>
{
public:
	tlm_initiator_socket<> init_socket;

	Initiator(sc_core::sc_module_name module_name);
	virtual ~Initiator();

	SC_HAS_PROCESS(Initiator);

private:
	sc_time read_dly;
	sc_time write_dly;

	unsigned char *dmi_ptr;
	uint64_t dmi_start_address;
	uint64_t dmi_end_address;


	void read_mem();
	void write_mem();
	unsigned char *read_buff, *write_buff;
	void read_write();
	size_t read_file(char *fname, void *buf, size_t len);
	bool compare(const unsigned char* read_buff, const unsigned char* write_buff, size_t len);

	tlm_sync_enum nb_transport_bw(	tlm::tlm_generic_payload& trans,tlm::tlm_phase& phase,	sc_core::sc_time& t);
	void invalidate_direct_mem_ptr(sc_dt::uint64 start_range, sc_dt::uint64 end_range);

};
