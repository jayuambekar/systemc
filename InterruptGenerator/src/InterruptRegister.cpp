#include "InterruptRegister.h"



InterruptRegister::InterruptRegister() :
  Register(0x0)
{
}

bool InterruptRegister::isRaise()
{
  if (GET_BIT(registerValue, RAISE) != 0x0)
  {
    return true;
  }
  return false;
}

void InterruptRegister::setRaise()
{
  registerValue = SET_BIT(registerValue, RAISE);
}

void InterruptRegister::clearRaise()
{
  registerValue = CLEAR_BIT(registerValue, RAISE);
}

bool InterruptRegister::isClear()
{
  if (GET_BIT(registerValue, CLEAR) != 0x0)
  {
    return true;
  }
  return false;
}

void InterruptRegister::setClear()
{
  registerValue = SET_BIT(registerValue, CLEAR);
}

void InterruptRegister::clearClear()
{
  registerValue = CLEAR_BIT(registerValue, CLEAR);
}
