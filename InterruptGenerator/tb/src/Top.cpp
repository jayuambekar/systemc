#include <Top.h>

Top :: Top(sc_core::sc_module_name module_name):
		sc_module(module_name)
	   ,interruptSignal("interruptSignal", 10)
{
	interruptGenerator = new InterruptGenerator("interruptGenerator");
	interruptGeneratorTb = new InterruptGeneratorTb("interruptGeneratorTb");

	interruptGenerator->interruptsOut(interruptSignal);
	interruptGeneratorTb->interruptsIn(interruptSignal);

	interruptGeneratorTb->initiatorSocket.bind(interruptGenerator->targetSocket);


}
