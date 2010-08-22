#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

int main(void) {
	LinkedList list; 
	list.Add(0);
	list.Add(1);
	list.Add(2);
	list.Add(3);

	{
		int index = 0;
		for (LinkedList::Iterator itr = list.Begin();
			itr.HasNext();)
		{
			std::cout << index << " :" << itr.Next() << std::endl;
			index++;
		}
	}

	list.Remove(1);
	list.RemoveAt(0);

	{
		int index = 0;
		for (LinkedList::Iterator itr = list.Begin();
			itr.HasNext();)
		{
			std::cout << index << " :" << itr.Next() << std::endl;
			index++;
		}
	}

	list.Clear();

	{
		int index = 0;
		for (LinkedList::Iterator itr = list.Begin();
			itr.HasNext();)
		{
			std::cout << index << " :" << itr.Next() << std::endl;
			index++;
		}
	}

	std::cout << "Hello World" << std::endl;
	return EXIT_SUCCESS;
}