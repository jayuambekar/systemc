#include <NandGate.h>

NandGate :: NandGate(sc_core::sc_module_name module_name)
			:sc_module(module_name)
			, a("a")
			, b("b")
			, res("res")
{
	SC_METHOD(NandOperation);
	sensitive << a << b;
}

void NandGate :: NandOperation()
{
	res.write(!(a.read() && b.read()));
}

