#pragma once

#include <systemc>

class TestbenchHalfAdder : public sc_core::sc_module
{
public:
	sc_core::sc_out<bool> in1;
	sc_core::sc_out<bool> in2;
	sc_core::sc_in<bool> sum;
	sc_core::sc_in<bool> carry;

	TestbenchHalfAdder(sc_core::sc_module_name module_name);
private:
	void test();
	void monitor();

	SC_HAS_PROCESS(TestbenchHalfAdder);
};
