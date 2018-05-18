/*
 * main.cc
 *
 *  Created on: 18-May-2018
 *      Author: mgarodi
 */

#include <iostream>
#include <systemc>

#include <temp.h>
using namespace std;
using namespace sc_core;

int sc_main(int argc,char * argv[])
{
	cout << "Hello World" << endl;
	cout << add(2,5) << endl;
	sc_signal<int> signal;
	return 0;
}
