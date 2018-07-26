#include <Top.h>

Top :: Top(sc_core::sc_module_name module_name)
	: sc_module(module_name)
{
	initiatorSocket = new InitiatorSocket("initiatorSocket");
	busTargetSocket = new BusTargetSocket("busTargetSocket");

	busInitiatorSocket = new BusInitiatorSocket("busInitiatorSocket");
	targetSocket = new TargetSocket("targetSocket");

	initiatorSocket->init_socket(busTargetSocket->bus_target_socket);
	busInitiatorSocket->bus_init_socket(targetSocket->target_socket);

}
