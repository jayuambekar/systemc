#include <systemc>
#include <adder.h>
#include <iostream>

using namespace sc_core;
using namespace std;
int sc_main(int argc, char *argv[])
{
	Adder adder("adder");
	
	sc_buffer<int> a_sig("a_sig");
	sc_signal<int> b_sig("b_sig");
	sc_signal<int> result_sig("result_sig");

	adder.a(a_sig);
	adder.b(b_sig);
	adder.result(result_sig);

	sc_start(10,SC_NS); // Starts the simulation
	a_sig.write(10);
	b_sig.write(10);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	a_sig.write(20);
	b_sig.write(20);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " " << result_sig.read() << endl;

	a_sig.write(30);
	b_sig.write(30);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	a_sig.write(40);
	b_sig.write(40);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	a_sig.write(50);
	b_sig.write(50);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	a_sig.write(50);
	b_sig.write(50);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	a_sig.write(50);
	b_sig.write(50);
	sc_start(1,SC_NS);
	cout << "[ " << sc_time_stamp() << " ]" << result_sig.read() << endl;

	return 0;
}