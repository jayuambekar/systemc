#pragma once

#include <systemc>
#include <TargetSocket.h>
#include <InitiatorSocket.h>
#include <BusInitiatorSocket.h>
#include <BusTargetSocket.h>

class Top : public sc_core::sc_module
{
 public:
	Top(sc_core::sc_module_name module_name);

 private:
	TargetSocket *targetSocket;
	InitiatorSocket *initiatorSocket;
	BusInitiatorSocket *busInitiatorSocket;
	BusTargetSocket *busTargetSocket;



};
