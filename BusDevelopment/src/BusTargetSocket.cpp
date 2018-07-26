#include "BusTargetSocket.h"

BusTargetSocket :: BusTargetSocket(sc_core::sc_module_name moduleName)
			: sc_module(moduleName)
			, bus_target_socket("bus_target_socket")
{
	busTargetMemory = new unsigned char();
	bus_target_socket.register_b_transport(this, &BusTargetSocket::b_transport);
}

void BusTargetSocket :: b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time & delay)
{
  tlm::tlm_command 	command           = payload.get_command();
  uint64_t          address           = payload.get_address();
  unsigned char*    dataPointer       = payload.get_data_ptr();
  unsigned int      dataLength        = payload.get_data_length();
  unsigned char*    byteEnablePointer = payload.get_byte_enable_ptr();
  unsigned int      streamingWidth    = payload.get_streaming_width();

  if (address%4 != 0)
  {
    payload.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
    return;
  }

  if (byteEnablePointer != 0)
  {
    payload.set_response_status(tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE);
    return;
  }

  if (dataLength != 4 || streamingWidth != dataLength)
  {
    payload.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
    return;
  }

  if (command == tlm::TLM_READ_COMMAND)
  {
	  memcpy(dataPointer, &busTargetMemory[address], dataLength);
  }
  else if (command == tlm::TLM_WRITE_COMMAND)
  {
	  memcpy(&busTargetMemory[address], dataPointer, dataLength);
  }
  else
  {
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  }
  payload.set_response_status(tlm::TLM_OK_RESPONSE);
}


