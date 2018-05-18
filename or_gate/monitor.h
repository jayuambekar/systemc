//file: monitor.h
//this the monitor module
#include <systemc.h>

using namespace sc_core;
using  namespace sc_dt;

SC_MODULE(monitor)
{
	sc_in<sc_bool> m_a, m_b;
	sc_in<sc_bool> m_c;//both input and output of the OR module are to 
	//be monitored
	void prc_monitor()
	{
		cout <<" At "<< sc_time_stamp() << " input is : ";
		cout <<m_a<<" , "<<m_b<<" output is : "<<m_c<<endl;
	}

	SC_CTOR(monitor)
	{

		SC_METHOD(prc_monitor);
		sensitive << m_a <<m_b <<m_c;
		//whenever the i/p to the gate changes, 
		//or the o/p changes, the process prc_monitor triggers
	}
};