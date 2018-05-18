// File or_gate.h

#include <systemc>

using namespace sc_core;
using  namespace sc_dt;

SC_MODULE(or_gate)
{
	sc_in<sc_bool> a;
	sc_in<sc_bool> b;
	sc_out<sc_bool> c;

	void prc_or_gate() 
	{
		c = a | b;
	}

	SC_CTOR(or_gate)
	{
		SC_METHOD(prc_or_gate);
		sensitive << a << b;
	}
	
};