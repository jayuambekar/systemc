#pragma once

#include <systemc>
#include <Interconnect.h>
#include <Master.h>
#include <Target.h>

class Top : public sc_core::sc_module
{
 public:
	Top(sc_core::sc_module_name module_name, size_t num_slaves);

 private:
	sc_core::sc_signal<uint32_t> data_sig;
	sc_core::sc_signal<uint32_t> addr_sig;
	sc_core::sc_vector<sc_core::sc_signal<uint32_t>> data_out_sig;

	Master *master;
	Interconnect *interconnect;
	//Target **target;
	std::vector<Target> target;
};
