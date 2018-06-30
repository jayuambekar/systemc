#include <Top.h>

Top::Top(sc_core::sc_module_name module_name)
	: sc_module(module_name)
	, nand_a_sig("nand_a_sig")
	, nand_b_sig("nand_b_sig")
	, nand_res_sig("nand_res_sig")
	, xor_x_sig("xor_x_sig")
	, xor_y_sig("xor_y_sig")
	, xor_out_sig("xor_out_sig")
	, half_adder_in1_sig("half_adder_in1_sig")
	, half_adder_in2_sig("half_adder_in2_sig")
	, half_adder_sum_sig("half_adder_sum_sig")
	, half_adder_carry_sig("half_adder_carry_sig")
{
	nandGate = new NandGate("nandGate");
	nandtb = new TestbenchNand("nandtb");
	xorGate = new XorGate("xorGate");
	xortb = new TestbenchXor("xortb");
	halfAdder = new HalfAdder("halfAdder");
	halfAddertb = new TestbenchHalfAdder("halfAddertb");

	nandGate->a.bind(nand_a_sig);
	nandtb->a.bind(nand_a_sig);
	nandGate->b.bind(nand_b_sig);
	nandtb->b.bind(nand_b_sig);
	nandGate->res.bind(nand_res_sig);
	nandtb->res.bind(nand_res_sig);

	xorGate->x.bind(xor_x_sig);
	xortb->x.bind(xor_x_sig);
	xorGate->y.bind(xor_y_sig);
	xortb->y.bind(xor_y_sig);
	xorGate->out.bind(xor_out_sig);
	xortb->out.bind(xor_out_sig);

	halfAdder->in1.bind(half_adder_in1_sig);
	halfAddertb->in1.bind(half_adder_in1_sig);
	halfAdder->in2.bind(half_adder_in2_sig);
	halfAddertb->in2.bind(half_adder_in2_sig);
	halfAdder->sum.bind(half_adder_sum_sig);
	halfAddertb->sum.bind(half_adder_sum_sig);
	halfAdder->carry.bind(half_adder_carry_sig);
	halfAddertb->carry.bind(half_adder_carry_sig);

}