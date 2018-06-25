#include <StateTb.h>
#include <iostream>

using namespace std;

void StateTb :: Test()
{
	ev1_out.write(true);
	wait(10, SC_NS);

	ev2_out.write(true);
	wait(10, SC_NS);
}

void StateTb :: monitor()
{
	cout << "[ " << sc_time_stamp() << " ] " << state_res_in.read() << endl;
}
