#include <Top.h>
using namespace tlm;

Top :: Top(sc_core::sc_module_name module_name)
	: sc_module(module_name)
{
	memory = new Memory("memory");
	initiator = new Initiator("initiator");

	initiator->init_socket.bind(memory->mem_socket);
}
