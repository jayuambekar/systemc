#include <Top.h>
#include<iostream>

void Top :: T()
{
	std::string txt = "Hello world";

	for(int i = 0; i < txt.size(); i++)
	{
		queue.write(txt[i]);
	}

	for(int i = 0; i < txt.size(); i++)
	{
		std::cout << queue.read();
	}
	std::cout << std::endl;
}
