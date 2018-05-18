#include <andgate.h>

AndGate::AndGate(sc_core::sc_module_name name) :
	  sc_module(name)
	, a("a")
	, b("b")
	, result("result")
{
	SC_METHOD(doAnd);
}

void AndGate::doAnd()
{

	result.write(a.read() && b.read());
	
}