#pragma once

#include <systemc>

class NandGate : public sc_core::sc_module
{
public:
	sc_core::sc_in<bool> a;
	sc_core::sc_in<bool> b;
	sc_core::sc_out<bool> res;

	NandGate(sc_core::sc_module_name module_name);
	
	SC_HAS_PROCESS(NandGate);

private:
	void NandOperation();
};
