#include "Register.h"

Register::Register(uint32_t resetValue):
	  registerValue(resetValue)
	, resetValue(resetValue)
{
}

Register& Register::operator=(uint32_t value) {
	registerValue = value;
	return (*this);
}
Register::operator uint32_t() const
{
	return getValue();
}

void Register::setValue(uint32_t value)
{
	registerValue = value;
}

void Register::setResetValue(uint32_t value)
{
	resetValue = value;
}

void Register::reset()
{
	registerValue = resetValue;
}

uint32_t Register::getValue() const
{
	return registerValue;
}

uint32_t Register::getResetValue() const
{
	return resetValue;
}
