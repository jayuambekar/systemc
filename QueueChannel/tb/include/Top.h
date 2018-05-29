#pragma once

#include <systemc>
#include <queue.h>

using namespace sc_core;

class Top : public sc_core::sc_module
{
public:
	Queue queue;

	SC_CTOR(Top): queue("queue", 100)
	{
		SC_THREAD(T);
	}
private:
	void T();
};
