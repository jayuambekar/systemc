#pragma once

#include <systemc>
#include <NandGate.h>
#include <XorGate.h>
#include <HalfAdder.h>
#include <TestbenchNand.h>
#include <TestbenchXor.h>
#include <TestbenchHalfAdder.h>


class Top : public sc_core::sc_module
{

public:
	Top(sc_core::sc_module_name module_name);
	
private:
	NandGate *nandGate;
	TestbenchNand *nandtb;

	XorGate *xorGate;
	TestbenchXor *xortb;

	HalfAdder *halfAdder;
	TestbenchHalfAdder *halfAddertb;

	sc_core::sc_signal<bool> nand_a_sig;
	sc_core::sc_signal<bool> nand_b_sig;
	sc_core::sc_signal<bool> nand_res_sig;

	sc_core::sc_signal<bool> xor_x_sig;
	sc_core::sc_signal<bool> xor_y_sig;
	sc_core::sc_signal<bool> xor_out_sig;

	sc_core::sc_signal<bool> half_adder_in1_sig;
	sc_core::sc_signal<bool> half_adder_in2_sig;
	sc_core::sc_signal<bool> half_adder_sum_sig;
	sc_core::sc_signal<bool> half_adder_carry_sig;
};

