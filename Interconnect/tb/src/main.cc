/*
 * main.cc
 *
 *  Created on: 28-May-2018
 *      Author: Jayshree
 */

#include <iostream>
#include <systemc>

#include <Top.h>

using namespace std;
using namespace sc_core;

int sc_main(int argc,char * argv[])
{
	Top top("top");
	sc_start();
	return 0;
}
