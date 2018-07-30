#include <Top.h>

int sc_main(int argc, char *argv[])
{
	Top top("top",1024);
	sc_core::sc_start(100, sc_core::SC_NS);
	return 0;
}
