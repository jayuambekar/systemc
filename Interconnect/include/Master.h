/*
 * Master.h
 *
 *  Created on: 28-May-2018
 *      Author: Jayshree
 */

#ifndef INCLUDE_TEMP_H_
#define INCLUDE_TEMP_H_

#include <systemc>
#include <iostream>

using namespace sc_core;
using namespace sc_dt;

SC_MODULE(Master)
{
private:
	void master_read();
	void master_write();

public:
	sc_out< sc_uint<8> > data_out;
	sc_out< sc_uint<8> > addr;

	sc_in<bool> read_en;
	sc_in<bool> write_en;

	SC_CTOR(Master)
	{
		SC_METHOD(master_read);
		sensitive << read_en << addr;

		SC_METHOD(master_write);
		sensitive << write_en << addr << data_out;
	}

};

#endif /* INCLUDE_TEMP_H_ */
