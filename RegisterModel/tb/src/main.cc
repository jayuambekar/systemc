
#include <Top.h>

#include <iostream>
#include <systemc>

int sc_main(int argc,char * argv[])
{
	Top top("top");
	sc_core::sc_start();

	return 0;
}
