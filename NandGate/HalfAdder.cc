#include <HalfAdder.h>

HalfAdder :: HalfAdder(sc_core::sc_module_name module_name)
			:sc_module(module_name)
			, in1("in1")
			, in2("in2")
			, sum("sum")
			, carry("carry")
{
	nandgate1 = new NandGate("nandgate1");
	nandgate1->a.bind(in1);
	nandgate1->b.bind(in2);

	nandgate2 = new NandGate("nandgate2");
	nandgate2->a.bind(in1);
	nandgate1->res.bind(sig1_2_3_5);
	nandgate2->b.bind(sig1_2_3_5);

	nandgate3 = new NandGate("nandgate3");
	nandgate3->a.bind(sig1_2_3_5);
	nandgate3->b.bind(in2);

	nandgate4 = new NandGate("nandgate4");
	nandgate2->res.bind(sig2_4);
	nandgate4->a.bind(sig2_4);
	nandgate3->res.bind(sig3_4);
	nandgate4->b.bind(sig3_4);

	nandgate4->res.bind(sum);

	nandgate5 = new NandGate("nandgate5");
	nandgate5->a.bind(sig1_2_3_5);
	nandgate5->b.bind(sig1_2_3_5);

	nandgate5->res.bind(carry);

}

