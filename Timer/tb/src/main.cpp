/*
 * main.cpp
 *
 *  Created on: 18-May-2018
 *      Author: jayshree
 */

#include <timerModule.h>
#include <iostream>
#include <systemc>
#include <timerModuleTb.h>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

int sc_main(int argc, char * argv[])
{
	timerModule timer("timer");
	timerModuleTb timerTb("timerTb");

	sc_clock clk_sig("my_clock", 20, SC_NS, 0.5);

	sc_signal<bool> reset_sig;
	sc_signal<sc_uint<8> > addr_sig;
	sc_signal<sc_uint<8> > data_in_sig;

	sc_buffer<bool> intr0_sig;
	sc_buffer<bool> intr1_sig;
	sc_signal<sc_uint<8> > data_out_sig;

	sc_signal<bool> read_en_sig;
	sc_signal<bool> write_en_sig;

	// Connect signals to timer and testbench instances
	timer.clock(clk_sig);
	timerTb.clock(clk_sig);

	timer.reset(reset_sig);
	timerTb.reset(reset_sig);

	timer.addr(addr_sig);
	timerTb.addr(addr_sig);

	timer.data_in(data_in_sig);
	timerTb.data_in(data_in_sig);

	timer.intr0(intr0_sig);
	timerTb.intr0(intr0_sig);

	timer.intr1(intr1_sig);
	timerTb.intr1(intr1_sig);

	timer.data_out(data_out_sig);
	timerTb.data_out(data_out_sig);

	timer.read_en(read_en_sig);
	timerTb.read_en(read_en_sig);

	timer.write_en(write_en_sig);
	timerTb.write_en(write_en_sig);


	sc_trace_file *Tf;
	Tf = sc_create_vcd_trace_file("traces");
	Tf->set_time_unit(1, SC_NS);

	sc_trace(Tf, clk_sig, "clk_sig");
	sc_trace(Tf, reset_sig, "reset_sig");
	sc_trace(Tf, addr_sig, "addr_sig");
	sc_trace(Tf, data_in_sig, "data_in_sig");
	sc_trace(Tf, intr0_sig, "intr0_sig");
	sc_trace(Tf, intr1_sig, "intr1_sig");
	sc_trace(Tf, data_out_sig, "data_out_sig");
	sc_trace(Tf, read_en_sig, "read_en_sig");
	sc_trace(Tf, write_en_sig, "write_en_sig");

	sc_start();
	sc_close_vcd_trace_file(Tf);

	// Start simulation
	//	sc_start();

	return 0;
}

