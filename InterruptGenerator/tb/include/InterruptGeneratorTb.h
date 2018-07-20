#pragma once

#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>

#include <InterruptRegister.h>

class InterruptGeneratorTb : public sc_core::sc_module
{
public:
	InterruptGeneratorTb(sc_core::sc_module_name module_name);
	tlm_utils::simple_initiator_socket<InterruptGeneratorTb, 32> initiatorSocket;
	sc_core::sc_vector<sc_core::sc_in<bool>> interruptsIn;

private:
	void test();
	void monitor();
	void read_Interrupt();
	void write_Interrupt();
	void read_write_interrupt();

	SC_HAS_PROCESS(InterruptGeneratorTb);

	size_t numInterrupts;

	std::vector<InterruptRegister> interruptRegisters;

};
