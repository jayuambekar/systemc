#pragma once

#include <systemc>
#include "tlm.h"

#define SET_BIT(num, n) ((num) | (1) << (n))
#define GET_BIT(num, n) ((num) & ((1) << (n)) >> (n))
#define CLEAR_BIT(num , n) ((num) &(!(1) << (n))

#define MAX_INTERRUPT 1024

class Register : public sc_core::sc_module
{
public:
	Register(sc_core::sc_module_name sc_module_name);
	SC_HAS_PROCESS(Register);

private:
	uint32_t reg_val;

	void set(uint32_t val);
	uint32_t get();
	void clear();

	void set_RAISE(uint32_t val);
	uint32_t get_RAISE();
	void clear_RAISE(uint32_t val);

	void set_CLEAR(uint32_t val);
	uint32_t get_CLEAR();
	void clear_CLEAR(uint32_t val);

};
