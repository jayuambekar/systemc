
#include <Top.h>

#include <iostream>
#include <systemc>

using namespace std;
using namespace sc_core;

int sc_main(int argc,char * argv[])
{
	Top top("top");
	sc_start();

	return 0;
}
