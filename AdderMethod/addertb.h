/*
 *	header file-> addertb.h
 *	
 */

#ifndef ADDERTB_H
#include <systemc>

using namespace sc_core;

SC_MODULE(AdderTb) 
{
 public:
	sc_out<int> a;
	sc_out<int> b;
	sc_in<int> result;

	SC_CTOR(AdderTb) :
	a("a"),
	b("b"),
	result("result")
	{
		SC_THREAD(test);
		
		SC_METHOD(monitor);
		sensitive << result;
		
	}
 private:
	void test();
	void monitor();
};
#endif
