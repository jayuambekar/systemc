#pragma once

#include <systemc>

class TestbenchXor : public sc_core::sc_module
{
public:
	sc_core::sc_out<bool> x;
	sc_core::sc_out<bool> y;
	sc_core::sc_in<bool> out;
	TestbenchXor(sc_core::sc_module_name module_name);
private:
	void test();
	void monitor();

	SC_HAS_PROCESS(TestbenchXor);
};
