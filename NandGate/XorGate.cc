#include <XorGate.h>

XorGate :: XorGate(sc_core::sc_module_name module_name)
			:sc_module(module_name)
			, x("x")
			, y("y")
			, out("out")
{
	nandgate1 = new NandGate("nandgate1");
	nandgate1->a.bind(x);
	nandgate1->b.bind(y);

	nandgate2 = new NandGate("nandgate2");
	nandgate2->a.bind(x);
	nandgate1->res.bind(sig1_2_3);
	nandgate2->b.bind(sig1_2_3);

	nandgate3 = new NandGate("nandgate3");
	nandgate3->a.bind(sig1_2_3);
	nandgate3->b.bind(y);

	nandgate4 = new NandGate("nandgate4");
	nandgate2->res.bind(sig2_4);
	nandgate4->a.bind(sig2_4);
	nandgate3->res.bind(sig3_4);
	nandgate4->b.bind(sig3_4);

	nandgate4->res.bind(out);




}

void XorGate :: XorOperation()
{
	
}

