/*
 *	src file-> main.cpp
 *	For binding the signals and ports
 */

#include <systemc>
#include <adder.h>
#include <addertb.h>
#include <iostream>

using namespace sc_core;
using namespace std;
int sc_main(int argc, char *argv[])
{
	Adder adder("adder");
	AdderTb addertb("addertb");
	
	sc_signal<int> a_sig("a_sig");
	sc_signal<int> b_sig("b_sig");
	sc_signal<int> result_sig("result_sig");

	// named binding
	adder.a(a_sig);
	addertb.a(a_sig);

	adder.b(b_sig);
	addertb.b(b_sig);
	
	adder.result(result_sig);
	addertb.result(result_sig);

	//start the simulation process
	sc_start(100, SC_NS);

	return 0;
}