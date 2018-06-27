#pragma once

#include <systemc>

using namespace sc_core;

enum state {A = 0, B, C, D };


class StateIP : public sc_core::sc_module
{
public:
	sc_in<bool> ev_in1;
	sc_in<bool> ev_in2;
	sc_in<bool> ev_in3;
	sc_out<int> state_res_out;

	sc_event e1, e2, e3;

	StateIP(sc_module_name module_name)
	{
		SC_THREAD(traverse);

		SC_METHOD(ev_in1_pin);
		sensitive << ev_in1.pos();

		SC_METHOD(ev_in2_pin);
		sensitive << ev_in2.pos();

		SC_METHOD(ev_in3_pin);
		sensitive << ev_in3.pos();
	}
	SC_HAS_PROCESS(StateIP);

private:
	void traverse();
	void ev_in1_pin();
	void ev_in2_pin();
	void ev_in3_pin();
};
