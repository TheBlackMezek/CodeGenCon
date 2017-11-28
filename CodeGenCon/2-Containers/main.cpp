
#include <iostream>

#include "IntVector.h"



int main()
{
	IntVector vec;

	vec.append(2);
	vec.append(5);
	vec.append(9);
	vec.append(1);
	vec.append(34);
	vec.append(91);
	vec.insert(999, 1);
	vec[0] = 983;
	vec.reserve(91);
	//vec.erase(0);

	std::cout << "CAPACITY: " << vec.getCapacity() << std::endl;
	std::cout << "SIZE: " << vec.getSize() << std::endl;
	std::cout << vec.front() << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < vec.getCapacity(); ++i)
	{
		if (i < vec.getSize())
		{
			std::cout << vec.at(i) << std::endl;
		}
		else
		{
			std::cout << "EMPTY" << std::endl;
		}
	}

	std::cin.get();

	return 0;
}
