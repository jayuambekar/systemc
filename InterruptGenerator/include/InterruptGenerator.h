#pragma once

#include <systemc>
#include <tlm_utils/simple_target_socket.h>

#include <InterruptRegister.h>

class InterruptGenerator : public sc_core::sc_module
{
public:
  tlm_utils::simple_target_socket<InterruptGenerator, 32> targetSocket;
  sc_core::sc_vector<sc_core::sc_out<bool>> interruptsOut;
  InterruptGenerator(sc_core::sc_module_name moduleName);
  SC_HAS_PROCESS(InterruptGenerator);

private:
  size_t numInterrupts;

  std::vector<InterruptRegister> interruptRegisters;
  void b_transport(tlm::tlm_generic_payload& payload, sc_core::sc_time& delay);

};
