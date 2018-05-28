/*
 * Target.h
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

#define TAREGT_MODULE_ZERO		0
#define TAREGT_MODULE_ONE		1
#define TAREGT_MODULE_TWO		2

SC_MODULE(Target)
{
private:
	sc_uint<8> target_one;
	sc_uint<8> target_two;
	sc_uint<8> target_three;

	void target_read();
	void target_write();

public:
	sc_in< sc_uint<8> > addr;
	sc_in< sc_uint<8> > data_in;
	sc_in<bool> read_en;
	sc_in<bool> write_en;

	SC_CTOR(Target)
	{
		SC_METHOD(target_read);
		sensitive << read_en << addr;

		SC_METHOD(target_write);
		sensitive << write_en << addr << data_in;
	}
};

#endif /* INCLUDE_TEMP_H_ */
