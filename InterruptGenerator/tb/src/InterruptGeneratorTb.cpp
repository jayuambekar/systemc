#include <InterruptGeneratorTb.h>
#include <time.h>

InterruptGeneratorTb :: InterruptGeneratorTb(sc_core::sc_module_name module_name, int numberOfInterrupts):
		sc_module(module_name)
	   ,initiatorSocket("initiatorSocket")
	   ,interruptsIn("interruptsIn", numberOfInterrupts)
	   ,numInterrupts(numberOfInterrupts)
	   ,interruptRegisters(numberOfInterrupts)
	   , monitorFlag(false)
{
	SC_THREAD(test);

	SC_METHOD(monitor);
	for(auto &interrupt : interruptsIn)
	{
		sensitive << interrupt;
	}
	dont_initialize();

}

void InterruptGeneratorTb :: test()
{
	wait(sc_core::SC_ZERO_TIME);
	resetTest();
	wait(10, sc_core::SC_NS);
	triggerTest();
	wait(10,sc_core::SC_NS);
	readWriteTest();
}

bool InterruptGeneratorTb::resetTest()
{
 uint32_t resetValue = 0x0;
 uint32_t value;
 for(size_t i = 0; i < numInterrupts; i++)
 {
	 value = readRegister(i);
	 if(readRegister(i) != resetValue)
	 {
		 std::cout << "Reset test failed for Register  " << i << std::endl;
		 std::cout << "Expected Value: " << resetValue  << ", Actual Value: " << value << std::endl;
		 std::cout << "[RESET_TEST: FAILED]" << std::endl;
		 std::cout << std::endl;
		 return false;
	 }
 }
 std::cout << "[RESET_TEST: PASSED]" << std::endl;
 std::cout << std::endl;
 return true;
}

bool InterruptGeneratorTb::readWriteTest()
{
	uint32_t writeValues[numInterrupts];
	uint32_t readValue;
	srand(time(NULL));
	for(size_t i = 0; i < numInterrupts; i++)
	{
		writeValues[i] = rand() % 3;
		writeRegister(i, writeValues[i]);
	}

	for(size_t i = 0; i < numInterrupts; i++)
	{
		readValue = readRegister(i);
		if(readValue != writeValues[i])
		{
			std::cout << "Read write test failed for Register : " << i << ", Expected Value : "
					<< std::hex << "0x" << writeValues[i] << ", Actual Value: " << "0x"<< readValue << std::endl;
			std::cout << "[READ_WRITE_TEST:FAILED]" << std::endl;
			std::cout << std::endl;
			return false;
		}
	}
	std::cout << "[READ_WRITE_TEST:PASSED]" << std::endl;
	std::cout << std::endl;
	return true;
}

bool InterruptGeneratorTb :: triggerTest()
{
	bool interruptStatus[numInterrupts];
	srand(time(NULL));
	for(size_t i = 0; i < numInterrupts; i++)
	{
		interruptStatus[i] = rand()%2;
		if(interruptStatus[i])
		{
			setInterrupt(i, true);
			wait(sc_core::SC_ZERO_TIME);
			if(!interruptsIn[i].read())
			{
				std::cout << "Unable to set interrupt " <<  i << std::endl;
				std::cout << "[INTERRUPT_TEST:FAILED]" << std::endl;
				std::cout << std::endl;
				return false;
			}
		}
	}

	for(size_t i = 0; i < numInterrupts; i++)
	{
		if(interruptStatus[i])
		{
			setInterrupt(i, false);
			wait(sc_core::SC_ZERO_TIME);
			if(interruptsIn[i].read())
			{
				std::cout << "Unable to clear interrupt " <<  i << std::endl;
				std::cout << "[INTERRUPT_TEST:FAILED]" << std::endl;
				std::cout << std::endl;
				return false;
			}
		}
		else
		{
			if(interruptsIn[i].read())
			{
				std::cout << "Interrupt set unexpectedly " <<  i << std::endl;
				std::cout << "[INTERRUPT_TEST:FAILED]" << std::endl;
				std::cout << std::endl;
				return false;
			}
		}
	}
	std::cout << "[INTERRUPT_TEST:PASSED]" << std::endl;
	std::cout << std::endl;
	return true;
}

uint32_t InterruptGeneratorTb::readRegister(int index)
{
	tlm::tlm_generic_payload trans;
	sc_core::sc_time delay = sc_core::sc_time(10, sc_core::SC_NS);

	uint32_t value;
	trans.set_command(tlm::TLM_READ_COMMAND);
	trans.set_address(index*4);
	trans.set_data_ptr((unsigned char *) (&value));
	trans.set_streaming_width(4);
	trans.set_data_length(4);
	trans.set_dmi_allowed(false);
	trans.set_byte_enable_ptr(0);
	trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

	initiatorSocket->b_transport(trans, delay);

	if (trans.is_response_error())
	{
		SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
	}

	return value;
}

void InterruptGeneratorTb::writeRegister(int index, uint32_t value)
{
	tlm::tlm_generic_payload trans;
	sc_core::sc_time delay = sc_core::sc_time(10, sc_core::SC_NS);

	trans.set_command(tlm::TLM_WRITE_COMMAND);
	trans.set_address(index*4);
	trans.set_data_ptr((unsigned char *) (&value));
	trans.set_streaming_width(4);
	trans.set_data_length(4);
	trans.set_dmi_allowed(false);
	trans.set_byte_enable_ptr(0);
	trans.set_response_status(tlm::TLM_INCOMPLETE_RESPONSE);

	initiatorSocket->b_transport(trans, delay);

	if (trans.is_response_error())
	{
		SC_REPORT_ERROR("[TLM-2]", trans.get_response_string().c_str());
	}
}

void InterruptGeneratorTb :: setInterrupt(int index, bool status)
{
	if(status)
	{
		writeRegister(index, 0x1);
	}
	else
	{
		writeRegister(index, 0x2);
	}
}

void InterruptGeneratorTb :: monitor()
{
	int i = 0;
	if(!monitorFlag)
	{
		return;
	}
	for(auto &interrupt : interruptsIn)
	{
		if(interrupt.value_changed_event().triggered())
		{
			if(interrupt.read())
			{
				std::cout << "[ " << sc_core::sc_time_stamp() << " ] Interrupt raised : Intr  "<< i <<" " << std::endl;
			}
			else{
				std::cout << "[ " << sc_core::sc_time_stamp() << " ] Interrupt cleared : Intr  "<< i <<" " << std::endl;
			}
		}
		i++;
	}
}
