#pragma once

#include <systemc>

class TestbenchNand : public sc_core::sc_module
{
public:
	sc_core::sc_out<bool> a;
	sc_core::sc_out<bool> b;
	sc_core::sc_in<bool> res;

	TestbenchNand(sc_core::sc_module_name module_name);

private:
	void test();
	void monitor();

	SC_HAS_PROCESS(TestbenchNand);
};