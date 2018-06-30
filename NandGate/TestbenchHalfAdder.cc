#include <TestbenchHalfAdder.h>
#include <iostream>

TestbenchHalfAdder::TestbenchHalfAdder(sc_core::sc_module_name module_name):
  sc_module(module_name)
, in1("in1")
, in2("in2")
, sum("sum")
, carry("carry")

{
	SC_THREAD(test);

	SC_METHOD(monitor);
	sensitive << sum << carry;
}

void TestbenchHalfAdder::test()
{
	wait(1, sc_core::SC_NS);
	in1.write(0);
	in2.write(0);
	std::cout <<"[HalfAdder-TB][ " << sc_core::sc_time_stamp() << " ] [0, 0]" << std::endl;
	wait(1, sc_core::SC_NS);
	in1.write(0);
	in2.write(1);
	std::cout <<"[HalfAdder-TB][ " << sc_core::sc_time_stamp() << " ] [0, 1]" << std::endl;
	wait(1 , sc_core::SC_NS);
	in1.write(1);
	in2.write(0);
	std::cout <<"[HalfAdder-TB][ " << sc_core::sc_time_stamp() << " ] [1, 0]" << std::endl;
	wait(1 , sc_core::SC_NS);
	in1.write(1);
	in2.write(1);
	std::cout <<"[HalfAdder-TB][ " << sc_core::sc_time_stamp() << " ] [1, 1]" << std::endl;
	wait(1 , sc_core::SC_NS);
}

void TestbenchHalfAdder::monitor()
{
	std::cout <<"[HalfAdder][ " << sc_core::sc_time_stamp() << " ] "
		<< carry.read() << "," << sum.read() << std::endl;
}
