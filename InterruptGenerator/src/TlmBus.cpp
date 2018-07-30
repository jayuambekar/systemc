#include <TlmBus.h>

TlmBus::TlmBus(sc_core::sc_module_name moduleName, size_t noOfInitSockets)
		:sc_module(moduleName)
		,busTargetSocket("busTargetSocket")
		,busInitSocket("busInitSocket", noOfInitSockets)
{
	busTargetSocket.register_b_transport(this, &TlmBus::b_transport);
}

void TlmBus::b_transport(tlm::tlm_generic_payload &payload, sc_core::sc_time &delay)
{
	uint64_t address = payload.get_address();
	if(0x0 <= address && address < 0x800){
		busInitSocket[0]->b_transport(payload, delay);

	}
	else if(0x800 <= address)
	{
		payload.set_address(address - 0x800);
		busInitSocket[1]->b_transport(payload, delay);
		payload.set_address(address);
	}


}
