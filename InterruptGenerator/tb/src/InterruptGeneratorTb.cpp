#include <InterruptGeneratorTb.h>

InterruptGeneratorTb :: InterruptGeneratorTb(sc_core::sc_module_name module_name):
		sc_module(module_name)
	   ,initiatorSocket("initiatorSocket")
	   ,interruptsIn("interruptsIn", 10)
{
	SC_THREAD(test);

	SC_METHOD(monitor);
}

void InterruptGeneratorTb :: test()
{
	wait(1, sc_core::SC_NS);

	for(int i=0; i<10; i++)
	{
		interruptsIn[i];

		std::cout << "[ " << sc_core::sc_time_stamp() << " ] " << " interrupt "<< i << std::endl;
	}

	wait(10, sc_core::SC_NS);
}

void InterruptGeneratorTb :: monitor()
{
	std::cout << "[ " << sc_core::sc_time_stamp() << " ] Interrupt asserted : Intr0 " << std::endl;
}

