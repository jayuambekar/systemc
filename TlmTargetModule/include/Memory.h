#pragma once

#include <systemc>
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"

class Memory : public sc_core::sc_module //, tlm::tlm_fw_transport_if<>
{
public:
	//tlm::tlm_target_socket<> mem_socket;
	tlm_utils::simple_target_socket<Memory> mem_socket;
	Memory(sc_core::sc_module_name module_name, size_t size = 100);

private:
	unsigned char *memory;
	size_t size;

	void b_transport(tlm::tlm_generic_payload &trans, sc_core::sc_time &delay);
	/*tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_core::sc_time& t); */
	bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data);
	/* unsigned int transport_dbg(tlm::tlm_generic_payload& trans);*/

};
