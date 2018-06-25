#pragma once

#include <systemc>
using namespace sc_core;

SC_MODULE(StateTb)
{
public:
	sc_in<int> state_res_in;
	sc_out<bool> ev1_out;
	sc_out<bool> ev2_out;
	sc_out<bool> ev3_out;

	SC_CTOR(StateTb)
	{
		SC_THREAD(Test);

		SC_METHOD(monitor);
		sensitive << state_res_in;
	}

private:
	void Test();
	void monitor();
};
