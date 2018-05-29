#pragma once

#include <systemc>
#include <stdint.h>

class Master : public sc_core::sc_module
{
 public:
	Master(sc_core::sc_module_name module_name);
	sc_core::sc_out<uint32_t> data_out;
	sc_core::sc_out<uint32_t> addr_out;

 private:

};
