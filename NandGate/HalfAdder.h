#pragma once

#include <systemc>
#include <NandGate.h>

using namespace sc_core;

class HalfAdder : public sc_module
{
public:
	sc_core::sc_in<bool> in1;
	sc_core::sc_in<bool> in2;
	sc_core::sc_out<bool> sum;
	sc_core::sc_out<bool> carry;

	HalfAdder(sc_core::sc_module_name module_name);
	
	SC_HAS_PROCESS(HalfAdder);

private:
	NandGate *nandgate1;
	NandGate *nandgate2;
	NandGate *nandgate3;
	NandGate *nandgate4;
	NandGate *nandgate5;

	sc_core::sc_buffer<bool> sig1_2_3_5;
	sc_core::sc_buffer<bool> sig2_4;
	sc_core::sc_buffer<bool> sig3_4;
	
};