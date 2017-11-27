#pragma once

#include <iostream>



template<typename T>
T add(T a, T b)
{
	return a + b;
}

template<typename T>
void print(T a)
{
	std::cout << a << std::endl;
}

template<typename T>
T min(T a, T b)
{
	return (a < b) * a + (b < a) * b;
}

template<typename T>
T max(T a, T b)
{
	return (a > b) * a + (b > a) * b;
}
