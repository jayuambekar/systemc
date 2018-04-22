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
		SC_METHOD(add);
		sensitive << a << b;
	}

private:
	void add();
};
#endif