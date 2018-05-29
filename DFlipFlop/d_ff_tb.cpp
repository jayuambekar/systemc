#include <d_ff_tb.h>
#include <iostream>

using namespace sc_core;
using namespace std;

void t_ff_tb :: tb_method()
{

	din.write(0);
	wait(5, SC_NS);
	 
	din.write(1);
	wait(10, SC_NS);
	 
	din.write(0);
	wait(15, SC_NS);
	 
	din.write(1);
	wait(10, SC_NS);
	 
	din.write(0);
	wait(20, SC_NS);
	 
	din.write(1);
	wait(10, SC_NS);
	 
	din.write(0);
	//wait(8, SC_NS);
}

void t_ff_tb :: monitor()
{
	cout << "[ " << sc_time_stamp() << " ] " << dout.read() << endl;
}