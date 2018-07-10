#include "InterruptGenerator.h"

InterruptGenerator::InterruptGenerator(sc_core::sc_module_name moduleName) :
  sc_module(moduleName)
  , targetSocket("targetSocket")
  , interruptsOut("interruptsOut", 10)
  , numInterrupts(10)
  , interruptRegisters(10)
{
  targetSocket.register_b_transport(this, &InterruptGenerator::b_transport);
}

void InterruptGenerator::b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time & delay)
{
  tlm::tlm_command 	command           = payload.get_command();
  uint64_t          address           = payload.get_address();
  unsigned char*    dataPointer       = payload.get_data_ptr();
  unsigned int      dataLength        = payload.get_data_length();
  unsigned char*    byteEnablePointer = payload.get_byte_enable_ptr();
  unsigned int      streamingWidth    = payload.get_streaming_width();


  if ((address + dataLength) > (numInterrupts*4) || address%4 != 0)
  {
    payload.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
    return;
  }

  if (byteEnablePointer != 0)
  {
    payload.set_response_status(tlm::TLM_BYTE_ENABLE_ERROR_RESPONSE);
  }

  if (dataLength != 4 || streamingWidth != dataLength)
  {
    payload.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
  }

  if (command == tlm::TLM_READ_COMMAND)
  {
    uint32_t *value = (uint32_t *)dataPointer;
    *value = interruptRegisters[address / 4].getValue();
  }
  else if (command == tlm::TLM_WRITE_COMMAND)
  {
    uint32_t *value = (uint32_t *)dataPointer;
    interruptRegisters[address / 4].setValue(*value);
  }
  else
  {
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  }
  payload.set_response_status(tlm::TLM_OK_RESPONSE);

}
