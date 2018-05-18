/*
 *	src file-> addertb.cpp
 *	For implementing test() method
 *	with given inputs
 * 	& monitor() method to print the timestamp between the results.
 */

#include <iostream>
#include <addertb.h>

using namespace std;

void AdderTb::test()
{

	a.write(0);
	b.write(0);
	
	wait(5,SC_NS);
	
	a.write(5);
	b.write(0);

	wait(2,SC_NS);
	
	a.write(5);
	b.write(10);

	wait(8,SC_NS);
	
	a.write(7);
	b.write(8);
	
}


void AdderTb::monitor()
{
	cout << "[ " << sc_time_stamp() << " ] " << result.read() << endl;
}
