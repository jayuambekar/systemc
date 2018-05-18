/*
 *	src file-> adder.cpp
 *	For implementing add() method
 */
#include <iostream>
#include <adder.h>

void Adder :: add()
{
	temp_result = a.read() + b.read();
	write_event.notify(2, SC_NS);
}

void Adder :: update_res()
{
	result.write(temp_result); 
}





//code changes with next_trigger()
/*
void Adder :: add()
{
	if(!flag)
	{
		temp_result = a.read() + b.read();
		next_trigger(2, SC_NS);
		flag = true;
	}
	else
	{
		result.write(temp_result);
		flag = false;
	}
}
*/