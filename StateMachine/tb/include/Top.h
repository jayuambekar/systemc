#pragma once

#include <systemc>
#include <StateIP.h>
#include <StateTb.h>

class Top : public sc_core::sc_module
{
 public:
	Top(sc_core::sc_module_name module_name);

 private:
	sc_core::sc_signal<bool> ev1_sig;
	sc_core::sc_signal<bool> ev2_sig;
	sc_core::sc_signal<int> state_sig;

	StateIP *stateIp;
	StateTb *stateTb;

};
