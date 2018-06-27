#pragma once

#include <systemc>
#include "tlm.h"

class Memory : public sc_core::sc_module, tlm::tlm_fw_transport_if<>
{
public:
	tlm::tlm_target_socket<> mem_socket;

	Memory(sc_core::sc_module_name module_name, size_t size = 100);

private:
	unsigned char *memory;
	size_t size;

	void b_transport(tlm::tlm_generic_payload &trans, sc_core::sc_time &delay);
	tlm::tlm_sync_enum nb_transport_fw();
	bool get_direct_mem_ptr();
	int transport_dbg();

};
