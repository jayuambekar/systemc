#include <systemc>
#include <iostream>

using namespace sc_core;


//MODULE tutorial

SC_MODULE(module_test)
{
	SC_CTOR(module_test)
	{
		std::cout << std::endl << " This is my first test module " << std::endl;
	}
};

//MAIN method

int sc_main(int args, char *argv[])
{
	module_test module_test1("module_test");

	sc_start(100, SC_NS);

	return 0;
}
