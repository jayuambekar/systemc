#pragma once

#include <systemc>
#include <tlm_utils/simple_initiator_socket.h>

#include <InterruptRegister.h>

class InterruptGeneratorTb : public sc_core::sc_module
{
public:
	InterruptGeneratorTb(sc_core::sc_module_name module_name, int numberOfInterrupts);
	tlm_utils::simple_initiator_socket<InterruptGeneratorTb, 32> initiatorSocket;
	sc_core::sc_vector<sc_core::sc_in<bool>> interruptsIn;

private:
	void test();
	void monitor();
	void setInterrupt(int index, bool status);
	void writeRegister(int index, uint32_t value);
	uint32_t readRegister(int index);
	bool triggerTest();
	bool resetTest();
	bool readWriteTest();


	SC_HAS_PROCESS(InterruptGeneratorTb);

	size_t numInterrupts;
	std::vector<InterruptRegister> interruptRegisters;
	bool monitorFlag;

};
