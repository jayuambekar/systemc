
#include <StateIP.h>

void StateIP :: traverse()
{
	state_res_out.write(s0);
	wait(e1);

	state_res_out.write(s1);
	wait(e2);


	state_res_out.write(s2);
}

void StateIP :: ev_in1_pin()
{
	e1.notify();
}

void StateIP :: ev_in2_pin()
{
	e2.notify();
}
