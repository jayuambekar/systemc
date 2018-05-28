/*
 * Interconnect.h
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

SC_MODULE(Interconnect)
{
private:
	void interconnect_read();
	void interconnect_write();

public:
	sc_in< sc_uint<8> > data_in;
	sc_in< sc_uint<8> > addr;

	sc_in<bool> read_en;
	sc_in<bool> write_en;

	SC_CTOR(Interconnect)
	{
		SC_METHOD(interconnect_read);
		sensitive << read_en << addr;

		SC_METHOD(interconnect_write);
		sensitive << write_en << addr << data_in;
	}

};

#endif /* INCLUDE_TEMP_H_ */
