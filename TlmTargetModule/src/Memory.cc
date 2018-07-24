
#include <Memory.h>

Memory::Memory(sc_core::sc_module_name module_name, size_t size) :
		sc_module(module_name),
		size(size)
{
	memory = new unsigned char[size];
	mem_socket.register_b_transport(this, &Memory::b_transport);
	mem_socket.register_get_direct_mem_ptr(this, &Memory::get_direct_mem_ptr);
	//mem_socket.bind(*this);
}

void Memory :: b_transport(tlm::tlm_generic_payload  &trans, sc_core::sc_time &delay)
{
	tlm::tlm_command cmd = trans.get_command();
	unsigned int width = trans.get_streaming_width();
	uint64_t address = trans.get_address();
	unsigned char *ptr = trans.get_data_ptr();
	unsigned int len = trans.get_data_length();
	unsigned char *byte = trans.get_byte_enable_ptr();

	if(byte != 0 || len > 4 || width < len || address+len > size)
	{
		trans.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
		return;
	}

	if(cmd == tlm::TLM_WRITE_COMMAND)
	{
		memcpy(&memory[address], ptr, len);
	}
	else if(cmd == tlm::TLM_READ_COMMAND)
	{
		memcpy(ptr, &memory[address], len);
	}
	else
	{
		std::cout << "Command not available.. " << std::endl;
	}
	if(address <= 0x50){
		trans.set_dmi_allowed(true);
	}
	trans.set_response_status(tlm::TLM_OK_RESPONSE);
}

/*tlm::tlm_sync_enum Memory :: nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase, sc_core::sc_time& t)
{
	return tlm::TLM_COMPLETED;
}
*/

bool Memory :: get_direct_mem_ptr(tlm::tlm_generic_payload& trans, tlm::tlm_dmi& dmi_data)
{
	dmi_data.allow_read_write();
	dmi_data.set_start_address(0);
	dmi_data.set_end_address(0x50);
	dmi_data.set_dmi_ptr(memory);
	mem_socket->invalidate_direct_mem_ptr(0x0, 0x50);
	return true;
}

/*
unsigned int Memory :: transport_dbg(tlm::tlm_generic_payload& trans)
{
	return 0;
}
*/

