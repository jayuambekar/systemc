#include <Interconnect.h>

Interconnect::Interconnect(sc_core::sc_module_name module_name, size_t num_slaves)
	: sc_module(module_name)
	, data_in("data_in")
	, addr_in("addr_in")
	, data_out("data_out",num_slaves)

{

}
