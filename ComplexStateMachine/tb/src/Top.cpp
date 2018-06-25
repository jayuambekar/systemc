#include <Top.h>
#include<iostream>

Top::Top(sc_core::sc_module_name module_name)
	: sc_module(module_name)
	, ev1_sig("ev1_sig")
	, ev2_sig("ev2_sig")
	, ev3_sig("ev3_sig")
	, state_sig("state_sig")
{
	stateIp = new StateIP("stateIp");
	stateTb = new StateTb("stateTb");

	stateIp -> ev_in1(ev1_sig);
	stateTb -> ev1_out(ev1_sig);

	stateIp -> ev_in2(ev2_sig);
	stateTb -> ev2_out(ev2_sig);

	stateIp -> ev_in3(ev3_sig);
	stateTb -> ev3_out(ev3_sig);

	stateIp -> state_res_out(state_sig);
	stateTb -> state_res_in(state_sig);
}

