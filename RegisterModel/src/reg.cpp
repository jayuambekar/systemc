/*

Register 32 bit
 * UNRESERVED (3:31)
 * OV (2:2)
 * CLEAR (1:1)
 * EN (0:0)



#include <iostream>

#define SET_BIT(num, n) ((num) | (1) << (n))
#define GET_BIT(num, n) ((num) & ((1) << (n)) >> (n))
#define CLEAR_BIT(num , n) ((num) &(! (1) << (n))


class Register
{
Public:
	virtual void set_reset_value(uint32_t value);
	virtual void set(uint32_t value) = 0;
	virtual uint32_t get() = 0;
};

Class ControlRegister : public Register
{
Public:
	ControlRegister(uint32_t reset_value) :
		value(reset_value)
		, reset_value(reset_value)
{
}
 void set(uint32_t value)
{
		reg_cntrl = value;
}

uint32_t get()
{
  return reg_cntrl;
}

void set_reset_value(uint32_t reset_value)
{
 	reset_value = reset_value;
}

uint32_t get_EN()
{
return GET_BIT(reg_cntrl, 0);

}


void set_EN()
{
reg_cntrl = SET_BIT(reg_cntrl, 0);
}

void clear_EN()
{
	reg_cntrl = CLEAR_BIT(reg_cntrl, 0);
}

uint32_t get_CLEAR()
{
return  GET_BIT(reg_cntrl, 1);

}


void set_CLEAR()
{
reg_cntrl = SET_BIT(reg_cntrl, 1);
}

void clear_CLEAR()
{
	reg_cntrl = CLEAR_BIT(reg_cntrl, 1);
}

uint32_t get_OV()
{
 return GET_BIT(reg_cntrl, 2);
}

void set_OV()
{
reg_cntrl = SET_BIT(reg_cntrl, 2);
}

void clear_ov()
{
reg_cntrl = CLEAR_BIT(reg_cntrl, 2);
}
Private:
	uint32_t reg_cntrl;
	uint32_t reset_value;
};

*/
