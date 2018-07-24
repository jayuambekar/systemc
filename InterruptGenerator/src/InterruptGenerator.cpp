#include "InterruptGenerator.h"

InterruptGenerator::InterruptGenerator(sc_core::sc_module_name moduleName, int numberOfInterrupts) :
  sc_module(moduleName)
  , targetSocket("targetSocket")
  , interruptsOut("interruptsOut", numberOfInterrupts)
  , numInterrupts(numberOfInterrupts)
  , interruptRegisters(numberOfInterrupts)
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
    return;
  }

  if (dataLength != 4 || streamingWidth != dataLength)
  {
    payload.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
    return;
  }

  if (command == tlm::TLM_READ_COMMAND)
  {
    uint32_t *readValue = (uint32_t *)dataPointer;
    *readValue = interruptRegisters[address / 4].getValue();
  }
  else if (command == tlm::TLM_WRITE_COMMAND)
  {
    uint32_t value = *((uint32_t *)dataPointer);
    if(GET_BIT(value,0) && !interruptRegisters[address/4].isRaise())
    {
    	interruptsOut[address/4].write(true);
    	value = CLEAR_BIT(value,1);
    }

    else if(GET_BIT(value, 1) && !interruptRegisters[address/4].isClear())
    {
    	interruptsOut[address/4].write(false);
    	value = CLEAR_BIT(value, 0);
    }

    interruptRegisters[address / 4].setValue(value);
  }
  else
  {
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  }
  payload.set_response_status(tlm::TLM_OK_RESPONSE);
}


