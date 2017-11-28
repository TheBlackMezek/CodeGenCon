
#include "IntVector.h"

#include <assert.h>
#include <cstring>



IntVector::IntVector()
{
	capacity = 2;
	data = new int[capacity];
	size = 0;
}

IntVector::~IntVector()
{
	delete[] data;
}



bool IntVector::grow(size_t minSize)
{
	assert(minSize <= 64000);

	if (minSize <= capacity)
	{
		return true;
	}

	while (capacity < minSize)
	{
		capacity *= 2;
	}

	int* tempData = new int[capacity];
	memcpy(tempData, data, size * sizeof(int));

	delete[] data;

	data = tempData;



	return true;
}




int& IntVector::operator[](const size_t i)
{
	assert(i < size && "Index must be within array");
	return data[i];
}

const int& IntVector::operator[](const size_t i) const
{
	assert(i < size && "Index must be within array");
	return data[i];
}

int& IntVector::at(size_t idx)
{
	assert(idx < size && "Index must be within array");
	return data[idx];
}

void IntVector::append(int val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	++size;
}

int* IntVector::c_ptr() const
{
	return data;
}

size_t IntVector::getCapacity() const
{
	return capacity;
}

size_t IntVector::getSize() const
{
	return size;
}

bool IntVector::empty() const
{
	return size == 0;
}

int IntVector::front() const
{
	assert(size > 0 && "Attempted to get first element of empty array");
	return data[0];
}

int IntVector::back() const
{
	assert(size > 0 && "Attempted to get last element of empty array");
	return data[size-1];
}

void IntVector::clear()
{
	size = 0;
}

void IntVector::erase(size_t i)
{
	assert(i < size && "Index must be within array");

	data[i] = 0;

	for (i; i < size - 1; ++i)
	{
		data[i] = data[i + 1];
	}

	--size;
}

int IntVector::count(int num) const
{
	int ret = 0;

	for (int i = 0; i < size; ++i)
	{
		ret += (data[i] == num);
	}

	return ret;
}

void IntVector::insert(int elm, size_t idx)
{
	assert(idx < size && "Index must be within array");

	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	for (int i = size; i > idx; --i)
	{
		data[i] = data[i - 1];
	}

	data[idx] = elm;
	++size;
}

void IntVector::reserve(size_t newSize)
{
	grow(newSize);
}

void IntVector::compact()
{
	if (size != capacity)
	{
		capacity = size;

		int* tempData = new int[capacity];
		memcpy(tempData, data, size * sizeof(int));

		delete[] data;

		data = tempData;
	}
}

