
#include <iostream>

#include "IntVector.h"
#include "TVector.h"



int main()
{
	TVector<float> vec;

	vec.append(2.4f);
	vec.append(5.4f);
	vec.append(9.4f);
	vec.append(55.4f);
	vec.append(34.4f);
	vec.append(91.4f);
	vec.insert(999.4f, 1);
	vec[0] = 983.4f;
	//vec.erase(0, 1);
	//vec.reserve(91);
	//vec.erase(0);

	std::cout << "CAPACITY: " << vec.getCapacity() << std::endl;
	std::cout << "SIZE: " << vec.getSize() << std::endl;
	std::cout << vec.empty() << std::endl;
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
