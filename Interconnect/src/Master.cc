#include <Master.h>

Master::Master(sc_core::sc_module_name module_name)
	: sc_module(module_name)
	, data_out("data_out")
	, addr_out("addr_out")
{

}
