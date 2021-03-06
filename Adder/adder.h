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

		//add method for read values from a and b
		SC_METHOD(add);
		sensitive << a << b;
		dont_initialize();
		
		//update_res method for updating the result
		SC_METHOD(update_res);
		sensitive << write_event;
		dont_initialize();
	}

private:

	int temp_result; //temp_result for reading the port values
	sc_event write_event;  //event for writing the result in result port

	void add();
	void update_res();
};
#endif
