#pragma once

#include <systemc>

//write interface
class queue_write_if : virtual public sc_core::sc_interface
{
public:
	virtual void write(char c) = 0;
};

//read interface
class queue_read_if : virtual public sc_core::sc_interface
{
public:
	virtual char read() = 0;
};

//queue_if implemention read and write interface
class queue_if : public queue_write_if
		       , public queue_read_if
{

};

