
#include <iostream>

#include "IntVector.h"
#include "TVector.h"
#include "TLinkedList.h"




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

	TLinkedList<int> list;

	list.append(62);
	list.append(11);
	list.append(62);
	list.append(3458);
	list.insert(100, 1);
	list.insert(200, 0);
	list.erase(2);

	//TLinkedList<int> llist(list);
	TLinkedList<int> llist;
	llist = list;

	std::cout << "SIZE: " << llist.getSize() << std::endl;
	std::cout << llist.count(62) << std::endl;
	std::cout << std::endl;
	
	for (int i = 0; i < llist.getSize(); ++i)
	{
		std::cout << llist.at(i) << std::endl;
	}

	std::cin.get();

	char lkj = 'A';
	char* c = &lkj;

	for (int i = 0; i < 1000; ++i)
	{
		std::cout << *c;
		++c;
	}

	std::cin.get();

	return 0;
}
