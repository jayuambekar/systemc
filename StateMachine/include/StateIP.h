#pragma once

#include <systemc>

using namespace sc_core;

enum state {s0 = 0, s1, s2 };


class StateIP : public sc_core::sc_module
{
public:
	sc_in<bool> ev_in1;
	sc_in<bool> ev_in2;
	sc_out<int> state_res_out;


	sc_event e1, e2;


	SC_CTOR(StateIP)
	{
		SC_THREAD(traverse);

		SC_METHOD(ev_in1_pin);
		sensitive << ev_in1.pos();

		SC_METHOD(ev_in2_pin);
		sensitive << ev_in2.pos();

	}


private:
	void traverse();
	void ev_in1_pin();
	void ev_in2_pin();
};
