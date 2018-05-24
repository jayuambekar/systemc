/*
 * timerMonitorTb.h
 *
 *  Created on: 19-May-2018
 *      Author: jayshree
 */

#ifndef TB_INCLUDE_TIMERMODULETB_H_
#define TB_INCLUDE_TIMERMODULETB_H_

#include <systemc>
#include <iostream>

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(timerModuleTb)
{
private:
	bool intr_ass_msg;

	void test();
	void monitor_intr0();
	void monitor_intr1();


public:
	sc_in<bool> clock;
	sc_out<bool> reset;
	sc_out<sc_uint<8>> addr;
	sc_out<sc_uint<8>> data_in;

	sc_in<bool> intr0;
	sc_in<bool> intr1;
	sc_in<sc_uint<8>> data_out;

	sc_out<bool> read_en;
	sc_out<bool> write_en;


	SC_CTOR(timerModuleTb)
	{
		intr_ass_msg = false;

		SC_THREAD(test);

		SC_METHOD(monitor_intr0);
		sensitive << intr0;

		SC_METHOD(monitor_intr1);
		sensitive << intr1;
	}
};

#endif /* TB_INCLUDE_TIMERMODULETB_H_ */
