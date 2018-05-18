//file: main_sc.cpp
//this is the main program which is used to
//instantiate all the modules and to bind them
//this also starts the simulation

#include <driver.h>
#include <monitor.h>
#include <or_gate.h> //all the header files should be included here.

int sc_main(int argc , char *argv[] )
{
	sc_signal <sc_bool> t_a, t_b, t_c;
	//signals t_a, t_b, t_c are used to connec all the modules

	or_gate g1("orgate");
	driver d1("driver");
	monitor m1("monitor");

	g1.a(t_a); 
	g1.b(t_b); 
	g1.c(t_c);
	//the above is called named binding

	d1.d_a(t_a); 
	d1.d_a(t_b); 
	
	m1.m_a(t_a); 
	m1.m_b(t_b); 
	m1.m_c(t_c);

	//d1<<t_a<<t_b;
	//m1<<t_a<<t_b<<t_c; //these are called positional binding

	sc_start(100,SC_NS);//start the simulation and run for 100 ns

	return 0;//return success
}