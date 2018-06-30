#pragma once

#include <systemc>
#include <NandGate.h>

class XorGate : public sc_core::sc_module
{
public:
	sc_core::sc_in<bool> x;
	sc_core::sc_in<bool> y;
	sc_core::sc_out<bool> out;

	XorGate(sc_core::sc_module_name module_name);
	
	SC_HAS_PROCESS(XorGate);

private:
	NandGate *nandgate1;
	NandGate *nandgate2;
	NandGate *nandgate3;
	NandGate *nandgate4;

	sc_core::sc_buffer<bool> sig1_2_3;
	sc_core::sc_buffer<bool> sig2_4;
	sc_core::sc_buffer<bool> sig3_4;
	
	void XorOperation();
};
