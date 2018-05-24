/*
 * timerModule.cpp
 *
 *  Created on: 19-May-2018
 *      Author: jayshree
 */


#include <timerModule.h>

void timerModule::read()
{
	/**
	* Read Registers :
	* TIMER_CNTRL, TIMER_VAL and TIMER_CMP
	*/
	if(read_en.read())
	{
		if(addr.read() == TIMER_CNTRL_ADDR)
		{
			data_out.write(timer_cntrl);
		}
		else if(addr.read() == TIMER_VAL_ADDR)
		{
			data_out.write(timer_val);
		}
		else if(addr.read() == TIMER_CMP_ADDR)
		{
			data_out.write(timer_cmp);
		}
	}
}

void timerModule::write()
{
	/**
	* Write to  Registers :
	* TIMER_CNTRL, TIMER_CMP and TIMER_INTR_STATUS
	**/

	if(write_en.read())
	{
		if (addr.read() == TIMER_CNTRL_ADDR)
		{
			timer_cntrl = data_in.read();
		}
		else if (addr.read() == TIMER_CMP_ADDR)
		{
			timer_cmp = data_in.read();
		}
		else if (addr.read() == TIMER_INTR_STATUS_ADDR)
		{
			//write 1 clear register
			if (data_in.read()[TIMER_INTR_STATUS_OV])
			{
				timer_intr_status[TIMER_CNTRL_OV] = 0;
				intr0.write(0);
			}
			if (data_in.read()[TIMER_INTR_STATUS_CMP])
			{
				timer_intr_status[TIMER_INTR_STATUS_CMP] = 0;
				intr1.write(0);
			}
		}
	}
}

void timerModule::increment()
{
	//overflow check
	if(!timer_cntrl[TIMER_CNTRL_EN])
				return;

	//if counter value reaches to 0xFF(MAX_VALUE)
	if(timer_val == MAX_VALUE)
	{
		timer_val = 0;
		if(timer_cntrl[TIMER_CNTRL_OV])
		{
			timer_intr_status[TIMER_INTR_STATUS_OV] = 1;
			intr0.write(true);
		}
	}
	else
	{
		timer_val = timer_val + 1;
	}

	// Timer value matches to compare value, set comparator interrupt
	if(timer_cntrl[TIMER_CNTRL_CMP] && timer_val == timer_cmp)
	{
		intr1.write(true);
		timer_intr_status[TIMER_INTR_STATUS_CMP] = 1;
	}
}

void timerModule::reset_timer()
{
	if(reset.read())
	{
		timer_cntrl = 0;
		timer_val = 0;
		timer_cmp = 0;
		timer_intr_status = 0;
		intr0 = 0;
		intr1 = 0;
	}
}


