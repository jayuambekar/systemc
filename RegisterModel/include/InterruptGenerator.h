#pragma once

#include <systemc>
#include "tlm.h"
#include "tlm_utils/simple_target_socket.h"
#include <Register.h>

class InterruptGenarator : public sc_core::sc_module
{
public:
	InterruptGenarator(sc_core::sc_module_name module_name);

private:
	Register *reg1;
	Register *reg2;


};
