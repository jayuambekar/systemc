#include <Top.h>

using namespace sc_core;

int sc_main(int argc,char * argv[])
{
	Top top("top");
/*	XorGate xorgate("xorgate");

	sc_signal<bool> sig1;
	sc_signal<bool> sig2;
	sc_signal<bool> result;

	xorgate.x(sig1);
	xorgate.y(sig2);
	xorgate.out(result);

	AndGate andgate("andgate");

	sc_signal<bool> and_sig1;
	sc_signal<bool> and_sig2;
	sc_signal<bool> and_sum;
	sc_signal<bool> and_carry;

	andgate.in1(and_sig1);
	andgate.in2(and_sig2);
	andgate.sum(and_sum);
	andgate.carry(and_carry);

*/
	sc_start();

	return 0;
}
