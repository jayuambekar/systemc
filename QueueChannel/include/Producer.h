/*
#pragma once
#include <systemc>
#include <queue_if.h>
#include <queue.h>

class Producer : public sc_core::sc_module
{
public:
	sc_core::sc_port<queue_write_if> out;

	void do_writes();

	SC_CTOR(Producer)
	{
		SC_THREAD(do_writes);
	}
};
*/
