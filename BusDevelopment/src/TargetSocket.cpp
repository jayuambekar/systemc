#include "TargetSocket.h"

TargetSocket::TargetSocket(sc_core::sc_module_name moduleName)
			: sc_module(moduleName)
			, target_socket("target_socket")
{
	targetMemory = new unsigned char();
	target_socket.register_b_transport(this, &TargetSocket::b_transport);
}

void TargetSocket::b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time & delay)
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
	  memcpy(dataPointer, &targetMemory[address], dataLength);
  }
  else if (command == tlm::TLM_WRITE_COMMAND)
  {
	  memcpy(&targetMemory[address], dataPointer, dataLength);
  }
  else
  {
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  }
  payload.set_response_status(tlm::TLM_OK_RESPONSE);
}


