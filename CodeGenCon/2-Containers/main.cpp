
#include <iostream>

#include "IntVector.h"
#include "TVector.h"
#include "TLinkedList.h"
#include "Stack.h"
#include "Queue.h"




int main()
{



	//TVector<float> vec;
	//
	//vec.append(2.4f);
	//vec.append(5.4f);
	//vec.append(9.4f);
	//vec.append(55.4f);
	//vec.append(34.4f);
	//vec.append(91.4f);
	//vec.insert(999.4f, 1);
	//vec[0] = 983.4f;
	////vec.erase(0, 1);
	////vec.reserve(91);
	////vec.erase(0);
	//
	//TVector<float> veec;
	//veec = vec;
	//
	//std::cout << "CAPACITY: " << veec.getCapacity() << std::endl;
	//std::cout << "SIZE: " << veec.getSize() << std::endl;
	//std::cout << veec.empty() << std::endl;
	//std::cout << std::endl;
	//
	//for (int i = 0; i < veec.getCapacity(); ++i)
	//{
	//	if (i < veec.getSize())
	//	{
	//		std::cout << veec.at(i) << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << "EMPTY" << std::endl;
	//	}
	//}

	//TLinkedList<int> list;
	//
	//list.append(62);
	//list.append(11);
	//list.append(62);
	//list.append(3458);
	//list.insert(100, 1);
	//list.insert(200, 0);
	//list.erase(2);
	//
	////TLinkedList<int> llist(list);
	//TLinkedList<int> llist;
	//llist = list;
	//
	//TLinkedList<int>::LinkedListIterator iterator = llist.begin();
	//++iterator;
	//TLinkedList<int>::LinkedListIterator iterator2 = iterator;
	//++iterator2;
	////iterator++; //this doesn't work

	//Stack<int> stack;
	//stack.push(9);
	//stack.push(4);
	//stack.push(1);

	Queue<int> queue;
	queue.push(9);
	queue.push(4);
	queue.push(1);

	std::cout << "SIZE: " << queue.size() << std::endl;
	std::cout << queue.back() << std::endl;
	std::cout << std::endl;
	
	int size = queue.size();
	for (int i = 0; i < size; ++i)
	{
		std::cout << queue.pop() << std::endl;
	}

	std::cin.get();

	return 0;
}
