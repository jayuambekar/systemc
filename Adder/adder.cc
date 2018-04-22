#include <iostream>
#include <adder.h>

using namespace std;

void Adder::add()
{
	cout << "[ " << sc_time_stamp() << " ]" << "In Adder" << endl;
	result.write(a.read() + b.read());
}