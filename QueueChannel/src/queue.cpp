#include <queue.h>

void Queue :: write(char c)
{
	if(n < sz)
	{
		n++;
		data[w++] = c;
		if (w == sz)
		{
			w = 0;
		}
	}
}


char Queue ::read()
{
	char c = 0;
	if(n > 0)
	{
		n--;
		c = data[r++];
		if(r == sz)
		{
			r = 0;
		}
	}
	return c;
}

