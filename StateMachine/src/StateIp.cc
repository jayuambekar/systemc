
#include <StateIP.h>

void StateIP :: traverse()
{
	CURR_STATE = S0;
		wait(e1);
	CURR_STATE = S1;
		wait(e2);
	CURR_STATE = S2;

	/*curr_st.curr_state = state.s0;
	wait(e1);

	curr_st.curr_state = state.s1;
	wait(e2);

	curr_st.curr_state = state.s2;*/
}

void StateIP :: ev_in1_pin()
{
	e1.notify();
}

void StateIP :: ev_in2_pin()
{
	e2.notify();
}
