#include <InterruptGeneratorTb.h>

InterruptGeneratorTb :: InterruptGeneratorTb(sc_core::sc_module_name module_name):
		sc_module(module_name)
	   ,initiatorSocket("initiatorSocket")
	   ,interruptsIn("interruptsIn", 10)
{

}

void InterruptGeneratorTb :: test()
{

}

void InterruptGeneratorTb :: monitor()
{

}

