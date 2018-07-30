#pragma once

#include <systemc>
#include "InterruptGenerator.h"
#include "InterruptGeneratorTb.h"
#include "TlmBus.h"

class Top : public sc_core::sc_module
{
public:
	Top(sc_core::sc_module_name module_name,int numberOfInterrupts);

private:
	InterruptGenerator *interruptGenerator[2];
	InterruptGeneratorTb *interruptGeneratorTb;
	TlmBus *tlmBus;

	sc_core::sc_vector<sc_core::sc_signal<bool>> interruptSignal;
};
