
#include <StateIP.h>

void StateIP :: traverse()
{
	state_res_out.write(A);
	wait(e1 | e2);

	if(e1.in_hierarchy())
		state_res_out.write(B);
	else
		state_res_out.write(C);

	wait(e3);
	state_res_out.write(D);

	state_res_out.write(C);
}

void StateIP :: ev_in1_pin()
{
	e1.notify();
}

void StateIP :: ev_in2_pin()
{
	e2.notify();
}

void StateIP :: ev_in3_pin()
{
	e3.notify();
}
