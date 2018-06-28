#pragma once

#include <systemc>
#include <Memory.h>
#include <Initiator.h>

class Top : public sc_core::sc_module
{
 public:
	Top(sc_core::sc_module_name module_name);

 private:
	Memory *memory;
	Initiator *initiator;

};
