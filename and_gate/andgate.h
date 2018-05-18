#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc>

class AndGate : public sc_core::sc_module
{
public:
	AndGate(sc_core::sc_module_name name);

	sc_core::sc_in<bool> a;
	sc_core::sc_in<bool> b;
	sc_core::sc_out<bool> result;

private:
	void doAnd();
	SC_HAS_PROCESS(AndGate);

};

#endif