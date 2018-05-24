/*
 * timerMonitor.h
 *
 *  Created on: 18-May-2018
 *      Author: jayshree
 */

#ifndef INCLUDE_TIMERMODULE_H_
#define INCLUDE_TIMERMODULE_H_

#include <systemc>
#include <iostream>

using namespace sc_core;
using namespace sc_dt;

#define MAX_VALUE 255

#define TIMER_CNTRL_ADDR 		0x0
#define TIMER_VAL_ADDR 			0x4
#define TIMER_CMP_ADDR 			0x8
#define	TIMER_INTR_STATUS_ADDR 	0xC

#define TIMER_CNTRL_EN		0
#define TIMER_CNTRL_CMP		1
#define TIMER_CNTRL_OV		2

#define TIMER_INTR_STATUS_CMP 	0
#define TIMER_INTR_STATUS_OV 	1


SC_MODULE(timerModule)
{
	private:
		sc_uint<8> timer_cntrl; // Timer control register
		sc_uint<8> timer_val; // Timer value register
		sc_uint<8> timer_cmp; // Timer compare register
		sc_uint<8> timer_intr_status; // Timer interrupt status register

		void increment();
		void read();
		void write();
		void reset_timer();

	public:
		sc_in<bool> clock; // Clock
		sc_in<bool> reset; // Reset
		sc_in<sc_uint<8> > addr; // In Address
		sc_in<sc_uint<8> > data_in; // In Data

		sc_out<bool> intr0; // Overflow interrupt
		sc_out<bool> intr1; // Comparator interrupt
		sc_out< sc_uint<8> > data_out; // Data out

		sc_in<bool> read_en; // Read enable
		sc_in<bool> write_en; // Write enable

		SC_CTOR(timerModule)
			{
				timer_cntrl = 0x00;
				timer_val = 0x00;
				timer_cmp = 0x00;
				timer_intr_status = 0x00;

				// Increment sensitive to timer clock
				SC_METHOD(increment);
				sensitive << clock.pos();
				dont_initialize();
				// Read sensitive to read_en or addr
				SC_METHOD(read);
				sensitive << read_en << addr;

				// Write sensitive to write_en, addr or data_in
				SC_METHOD(write);
				sensitive << write_en << addr << data_in;

				// reset_mod sensitive to reset
				SC_METHOD(reset_timer);
				sensitive << reset;
			}

};

#endif
