#pragma once

#include <systemc>
#include "InterruptGenerator.h"
#include "InterruptGeneratorTb.h"

class Top : public sc_core::sc_module
{
public:
	Top(sc_core::sc_module_name module_name);

private:
	InterruptGenerator *interruptGenerator;
	InterruptGeneratorTb *interruptGeneratorTb;

	sc_core::sc_vector<sc_core::sc_signal<bool>> interruptSignal;
};
