#pragma once

#include <systemc>

class Interconnect : public sc_core::sc_module
{
 public:
	Interconnect(sc_core::sc_module_name module_name, size_t num_slaves);
	sc_core::sc_in<uint32_t> data_in;
	sc_core::sc_in<uint32_t> addr_in;
	sc_core::sc_vector<sc_core::sc_out<uint32_t>> data_out;

 private:

};
