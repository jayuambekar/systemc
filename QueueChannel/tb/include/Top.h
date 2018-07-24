#pragma once

#include <systemc>
#include <queue.h>
//#include <Producer.h>

using namespace sc_core;

class Top : public sc_core::sc_module
{
public:
	Queue queue;
//	Producer *producer;

	SC_CTOR(Top): queue("queue", 100)
	{
		SC_THREAD(T);

		//producer = new Producer("producer");
		//producer->out(queue);
	}
private:
	void T();
};
