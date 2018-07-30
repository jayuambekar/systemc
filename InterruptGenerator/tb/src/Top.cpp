#include <Top.h>
#include <ostream>

Top :: Top(sc_core::sc_module_name module_name, int numberOfInterrupts):
		sc_module(module_name)
	   ,interruptSignal("interruptSignal", numberOfInterrupts)
{
	for(int i = 0; i < 2; i++)
	{
		std::string moduleName = "interrupGenerator";
		moduleName += std::to_string(i);
		interruptGenerator[i] = new InterruptGenerator(moduleName.c_str(), numberOfInterrupts/2);
	}
	interruptGeneratorTb = new InterruptGeneratorTb("interruptGeneratorTb", numberOfInterrupts);
	tlmBus = new TlmBus("tlmBus",2);

	for(int i=0; i < numberOfInterrupts/2; i++)
	{
		interruptGenerator[0]->interruptsOut[i](interruptSignal[i]);
	}
	for(int i=0; i < numberOfInterrupts/2; i++)
	{
		interruptGenerator[1]->interruptsOut[i](interruptSignal[i+numberOfInterrupts/2]);
	}

	interruptGeneratorTb->interruptsIn(interruptSignal);

	interruptGeneratorTb->initiatorSocket.bind(tlmBus->busTargetSocket);
	tlmBus->busInitSocket[0].bind(interruptGenerator[0]->targetSocket);
	tlmBus->busInitSocket[1].bind(interruptGenerator[1]->targetSocket);
}
