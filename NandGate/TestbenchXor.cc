#include <TestbenchXor.h>
#include <iostream>

TestbenchXor::TestbenchXor(sc_core::sc_module_name module_name) :
  sc_module(module_name)
, x("x")
, y("y")
, out("out")
{
	SC_THREAD(test);

	SC_METHOD(monitor);
	sensitive << out;
}

void TestbenchXor::test()
{
	wait(1, sc_core::SC_NS);
	x.write(0);
	y.write(0);
	std::cout <<"[Xor-TB][ " << sc_core::sc_time_stamp() << " ] [0, 0]" << std::endl;
	wait(1, sc_core::SC_NS);
	x.write(0);
	y.write(1);
	std::cout <<"[Xor-TB][ " << sc_core::sc_time_stamp() << " ] [0, 1]" << std::endl;
	wait(1 , sc_core::SC_NS);
	x.write(1);
	y.write(0);
	std::cout <<"[Xor-TB][ " << sc_core::sc_time_stamp() << " ] [1, 0]" << std::endl;
	wait(1 , sc_core::SC_NS);
	x.write(1);
	y.write(1);
	std::cout <<"[Xor-TB][ " << sc_core::sc_time_stamp() << " ] [1, 1]" << std::endl;
	wait(1 , sc_core::SC_NS);
}

void TestbenchXor::monitor()
{
	std::cout <<"[XOR][ " << sc_core::sc_time_stamp() << " ] " << out.read() << std::endl;
}
