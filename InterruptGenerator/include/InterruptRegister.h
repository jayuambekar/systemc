#pragma once

#include <Register.h>

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