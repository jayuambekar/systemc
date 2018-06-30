#include <TestbenchNand.h>
#include <iostream>

TestbenchNand::TestbenchNand(sc_core::sc_module_name module_name):
  sc_module(module_name)
, a("a")
, b("b")
, res("res")
{
	SC_THREAD(test);

	SC_METHOD(monitor);
	sensitive << res;
}

void TestbenchNand::test()
{
	wait(1, sc_core::SC_NS);
	a.write(0);
	b.write(0);
	std::cout <<"[NAND-TB][ " << sc_core::sc_time_stamp() << " ] [0, 0]" << std::endl;
	wait(1, sc_core::SC_NS);
	a.write(0);
	b.write(1);
	std::cout <<"[NAND-TB][ " << sc_core::sc_time_stamp() << " ] [0, 1]" << std::endl;
	wait(1, sc_core::SC_NS);
	a.write(1);
	b.write(0);
	std::cout <<"[NAND-TB][ " << sc_core::sc_time_stamp() << " ] [1, 0]" << std::endl;
	wait(1, sc_core::SC_NS);
	a.write(1);
	b.write(1);
	std::cout <<"[NAND-TB][ " << sc_core::sc_time_stamp() << " ] [1, 1]" << std::endl;
	wait(1, sc_core::SC_NS);
}

void TestbenchNand::monitor()
{
	std::cout <<"[NAND][ " << sc_core::sc_time_stamp() << " ] " << res.read() << std::endl;
}
