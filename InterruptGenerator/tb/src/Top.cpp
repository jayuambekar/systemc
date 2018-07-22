#include <Top.h>

Top :: Top(sc_core::sc_module_name module_name, int numberOfInterrupts):
		sc_module(module_name)
	   ,interruptSignal("interruptSignal", numberOfInterrupts)
{
	interruptGenerator = new InterruptGenerator("interruptGenerator", numberOfInterrupts);
	interruptGeneratorTb = new InterruptGeneratorTb("interruptGeneratorTb", numberOfInterrupts);

	interruptGenerator->interruptsOut(interruptSignal);
	interruptGeneratorTb->interruptsIn(interruptSignal);

	interruptGeneratorTb->initiatorSocket.bind(interruptGenerator->targetSocket);


}
