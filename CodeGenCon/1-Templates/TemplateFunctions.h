#pragma once

#include <iostream>
#include <assert.h>

#include "Structs.h"





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

template<>
void print(Starship a)
{
	print(a.id);
	print(a.name);
	print(a.shipClass);
}

template<typename T>
T min(T a, T b)
{
	return (a < b) * a + (b < a) * b;
}

template<>
char min(char a, char b)
{
	return (a > b) * a + (b > a) * b;
}

template<typename T>
T max(T a, T b)
{
	return (a > b) * a + (b > a) * b;
}

template<>
char max(char a, char b)
{
	return (a < b) * a + (b < a) * b;
}

template<typename T>
T clamp(T val, T minimum, T maximum)
{
	return val * (val >= minimum) * (val <= maximum) +
		minimum * (val < minimum) +
		maximum * (val > maximum);
}

template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<bool T>
void boolAssert(bool a)
{
	assert(T == a);
}

template<typename T>
void equalAssert(T a, T b)
{
	assert(a == b);
}

template<typename T>
void notEqualAssert(T a, T b)
{
	assert(a != b);
}
