#include <InterruptGenerator.h>

int sc_main(int argc, char *argv[])
{
  InterruptGenerator interruptGenerator("interruptGenerator");
	sc_core::sc_start(100, sc_core::SC_NS);
	getchar();
	return 0;
}