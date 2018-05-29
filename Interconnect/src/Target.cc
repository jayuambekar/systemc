#include <Target.h>

Target::Target(sc_core::sc_module_name module_name)
	: sc_module(module_name)
	, data_in("data_in")
{

}
