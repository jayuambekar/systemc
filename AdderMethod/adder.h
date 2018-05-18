/*
 *	header file-> adder.h
 *	for declaration of ports
 */

#ifndef ADDER_H
#include <systemc>

using namespace sc_core;

SC_MODULE(Adder) {
public:
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> result;


	SC_CTOR(Adder) :
	a("a"),
	b("b"),
	result("result")
	{
		temp_result = 0;
		flag = false;

		//add method for read values from a and b
		SC_METHOD(add);
		sensitive << a << b << update_event;
		dont_initialize();
	}

private:

	int temp_result; //temp_result for reading the port values
	bool flag;
	sc_event update_event;
	void add();
};
#endif
