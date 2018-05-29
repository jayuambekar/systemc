#include <queue_if.h>

class Queue : public queue_if, public sc_core::sc_object
{
public:
	Queue(char *nm, int sz)
	 : sc_core::sc_object(nm)
	 , sz(sz)
	{
		data = new char[sz];
		w = r = n = 0;
	}

	void write(char c);
	char read();

private:
	char *data;
	int sz, w, r, n;

};
