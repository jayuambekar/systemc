#include <Register.h>

Register :: Register(sc_core::sc_module_name module_name)
		: sc_module(module_name)

{
	reg_val = 0x0;
}

void Register :: set(uint32_t value)
{
	reg_val = value;
}

uint32_t Register :: get()
{
  return reg_val;
}

uint32_t Register :: get_CLEAR()
{
	return GET_BIT(reg_val, 1);
}

void Register :: set_CLEAR(uint32_t val)
{
	reg_val = SET_BIT(val, 1);
}

void Register :: clear_CLEAR(uint32_t val)
{
	//reg_val = CLEAR_BIT(val, 1);
}

uint32_t Register :: get_RAISE()
{
	return GET_BIT(reg_val, 1);
}

void Register :: set_RAISE(uint32_t val)
{
	reg_val = SET_BIT(val, 1);
}

void Register :: clear_RAISE(uint32_t val)
{
	//reg_val = CLEAR_BIT(val, 1);
}


