/*
#include <Producer.h>
#include <iostream>

using namespace sc_core;


void Producer :: do_writes()
{
	std::string tx = "hello Jayshree";

	for(int i = 0; i < tx.size(); i++)
	{
		wait(SC_ZERO_TIME);

		out -> write(tx[i]);

	}
}
*/
