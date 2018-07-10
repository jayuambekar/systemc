#pragma once
#include <stdint.h>

class Register
{
public:
	Register(uint32_t resetValue = 0x0);
	Register& operator=(uint32_t value);
	operator uint32_t() const;
	void setValue(uint32_t value);
	void setResetValue(uint32_t value);
	void reset();
	uint32_t getValue() const;
	uint32_t getResetValue() const;
protected:
	uint32_t registerValue;
	uint32_t resetValue;
};
