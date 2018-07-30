#pragma once

#include <Register.h>

#define SET_BIT(num,n) ((num) | (uint32_t(1) << (n)))
#define CLEAR_BIT(num,n) ((num) & ~(uint32_t(1) << (n)))
#define GET_BIT(num,n) (((num) >> n) & uint32_t(1))

enum InterruptRegisterBitField
{
  RAISE = 0,
  CLEAR
};

class InterruptRegister : public Register
{
  public:
    InterruptRegister();
    bool isRaise();
    void setRaise();
    void clearRaise();
    bool isClear();
    void setClear();
    void clearClear();
};
