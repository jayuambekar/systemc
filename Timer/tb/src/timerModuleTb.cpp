/*
 * timerModuleTb.cpp
 *
 *  Created on: 19-May-2018
 *      Author: jayshree
 */

#include <timerModuleTb.h>
#include <timerModule.h>

using namespace std;

void timerModuleTb::test()
{
	intr_ass_msg = true;
	addr.write(TIMER_CNTRL_ADDR);
	data_in.write(0x07);
	write_en.write(1);

	wait(0, SC_NS);
	write_en.write(0);

	while (true)
	{
		// At 0 ns: Write the value to timer_cmp = 135
		addr.write(TIMER_CMP_ADDR);
		data_in.write(135);
		write_en.write(1);
		wait(1, SC_NS);
		write_en.write(0);

		// At 18470 ns Read the value of register timer_val and print the value
		wait(18469, SC_NS);
		addr.write(TIMER_VAL_ADDR);
		read_en.write(1);
		wait(1, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << data_out.read() << endl;
		read_en.write(0);

		// At 19990 ns Read the value of register timer_val and print the value
		wait(1519, SC_NS);
		addr.write(TIMER_VAL_ADDR);
		read_en.write(1);
		wait(1, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << data_out.read() << endl;
		read_en.write(0);

		// At 20000 ns (20 uS), disable the timer
		wait(9, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] Disable timer" << endl;
		addr.write(TIMER_CNTRL_ADDR);
		data_in.write(0x06);
		write_en.write(1);
		wait(1, SC_NS);
		write_en.write(0);

		// At 20500 ns Read the value of register timer_val and print the value
		wait(499, SC_NS);
		addr.write(TIMER_VAL_ADDR);
		read_en.write(1);
		wait(1, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << data_out.read() << endl;
		read_en.write(0);

		// At 21000 ns. (21uS) enable the timer
		wait(499, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] Enable timer" << endl;
		addr.write(TIMER_CNTRL_ADDR);
		data_in.write(0x07);
		write_en.write(1);
		wait(1, SC_NS);
		write_en.write(0);

		// At 29990 Read the value of register timer_val and print the value
		wait(8989, SC_NS);
		addr.write(TIMER_VAL_ADDR);
		read_en.write(1);
		wait(1, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << data_out.read() << endl;
		read_en.write(0);

		// At 30000 ns (30 uS) change the value of timer_cmp
		wait(9, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] changing the value of timer_cmp" << endl;
		addr.write(TIMER_CMP_ADDR);
		data_in.write(100);
		write_en.write(1);
		wait(1, SC_NS);
		write_en.write(0);

		// At 40000 ns (40 uS) , Turn off the interrupt asserted messages
		wait(9999, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << "turn off the interrupt asserted messages" << endl;
		intr_ass_msg = false;

		// At 1000000 ns (1ms), Turn on the interrupt asserted messages
		wait(960000, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << "turn on interrupt asserted messages" << endl;
		intr_ass_msg = true;

		wait(750, SC_NS);
		addr.write(TIMER_VAL_ADDR);
		read_en.write(1);
		wait(1, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << data_out.read() << endl;
		read_en.write(0);

		// At 1010000 ns, Turn off the interrupt asserted messages
		wait(9249, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] " << "turn off interrupt asserted messages" << endl;
		intr_ass_msg = false;

		wait(98990000, SC_NS);
		cout << "[ " << sc_time_stamp() << " ] Stop simulation" << endl;
		sc_stop();
	}
}

void timerModuleTb::monitor_intr0()
{
	if(intr0.read() && intr_ass_msg)
	{
		cout << "[ " << sc_time_stamp() << " ] Interrupt asserted : Intr0 " << endl;
	}
}

void timerModuleTb::monitor_intr1()
{
	if(intr1.read() && intr_ass_msg)
	{
		cout << "[ " << sc_time_stamp() << " ] Interrupt asserted : Intr1 " << endl;
	}

}
