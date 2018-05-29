#pragma once

#include <systemc>

class Target : public sc_core::sc_module
{
 public:
	sc_core::sc_in<uint32_t> data_in;
	Target(sc_core::sc_module_name module_name);
 private:

};
