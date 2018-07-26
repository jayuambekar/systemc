#include "BusInitiatorSocket.h"

BusInitiatorSocket :: BusInitiatorSocket(sc_core::sc_module_name moduleName)
				: sc_module(moduleName)
				, bus_init_socket("bus_init_socket")
{

}
