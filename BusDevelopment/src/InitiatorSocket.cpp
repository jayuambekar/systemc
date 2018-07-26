#include "InitiatorSocket.h"

InitiatorSocket :: InitiatorSocket(sc_core::sc_module_name moduleName)
				: sc_module(moduleName)
				, init_socket("init_socket")
{

}
