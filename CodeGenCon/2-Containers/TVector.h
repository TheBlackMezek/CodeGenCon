#pragma once


#include <assert.h>


template<typename T>
class TVector
{
private:
	T* data;
	size_t capacity;
	size_t size;

	bool grow(size_t minSize);


public:
	TVector();
	~TVector();

	TVector(const TVector<T>& other);
	TVector<T>& operator=(const TVector<T> other);

	T& operator[](const size_t idx);
	const T& operator[](const size_t idx) const;

	T& at(size_t idx);
	void append(T val);
	T* c_ptr() const;
	size_t getCapacity() const;
	size_t getSize() const;
	bool empty() const;
	T front() const;
	T back() const;
	void clear();
	void erase(size_t idx);
	void erase(size_t start, size_t end);
	size_t count(T val) const;
	void insert(T elm, size_t idx);
	void reserve(size_t newSize);
	void compact();
	void pop();
};



template<typename T>
TVector<T>::TVector()
{
	capacity = 2;
	data = new T[capacity];
	size = 0;
}


template<typename T>
TVector<T>::~TVector()
{
	delete[] data;
}


template<typename T>
TVector<T>::TVector(const TVector<T>& other)
{
	data = new T[other.getCapacity()];
	memcpy(data, other.c_ptr(), sizeof(T) * other.getCapacity());
	capacity = other.getCapacity();
	size = other.getSize();
}
template<typename T>
TVector<T>& TVector<T>::operator=(const TVector<T> other)
{
	T* newData = new T[other.getCapacity()];
	memcpy(newData, other.c_ptr(), sizeof(T) * other.getCapacity());
	delete[] data;
	data = newData;

	capacity = other.getCapacity();
	size = other.getSize();

	return *this;
}


template<typename T>
bool TVector<T>::grow(size_t minSize)
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

	T* tempData = new T[capacity];
	memcpy(tempData, data, size * sizeof(T));

	delete[] data;

	data = tempData;



	return true;
}

template<typename T>
T& TVector<T>::operator[](const size_t idx)
{
	assert(idx < size && "Index must be within array");
	return data[idx];
}
template<typename T>
const T& TVector<T>::operator[](const size_t idx) const
{
	assert(idx < size && "Index must be within array");
	return data[idx];
}

template<typename T>
T& TVector<T>::at(size_t idx)
{
	assert(idx < size && "Index must be within array");
	return data[idx];
}
template<typename T>
void TVector<T>::append(T val)
{
	if (size == capacity)
	{
		bool didGrow = grow(size + 1);
		assert(didGrow);
	}

	data[size] = val;
	++size;
}
template<typename T>
T* TVector<T>::c_ptr() const
{
	return data;
}
template<typename T>
size_t TVector<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
size_t TVector<T>::getSize() const
{
	return size;
}
template<typename T>
bool TVector<T>::empty() const
{
	return size == 0;
}
template<typename T>
T TVector<T>::front() const
{
	assert(size > 0 && "Attempted to get first element of empty array");
	return data[0];
}
template<typename T>
T TVector<T>::back() const
{
	assert(size > 0 && "Attempted to get last element of empty array");
	return data[size - 1];
}
template<typename T>
void TVector<T>::clear()
{
	size = 0;
}
template<typename T>
void TVector<T>::erase(size_t idx)
{
	assert(idx < size && "Index must be within array");

	data[idx] = 0;

	for (idx; idx < size - 1; ++idx)
	{
		data[idx] = data[idx + 1];
	}

	--size;
}
template<typename T>
void TVector<T>::erase(size_t start, size_t end)
{
	assert(start < size && "Start index must be within array");
	assert(end < size && "End index must be within array");
	assert(start <= end && "Start must be before or at end");

	if (start == end)
	{
		erase(start);
	}
	else
	{
		int diff = end - start + 1;
		for (int i = start; i <= end; ++i)
		{
			data[i] = 0;
		}

		for (int i = start; i < size - diff; ++i)
		{
			data[i] = data[i + diff];
		}

		size -= diff;
	}
}
template<typename T>
size_t TVector<T>::count(T val) const
{
	int ret = 0;

	for (int i = 0; i < size; ++i)
	{
		ret += (data[i] == val);
	}

	return ret;
}
template<typename T>
void TVector<T>::insert(T elm, size_t idx)
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
template<typename T>
void TVector<T>::reserve(size_t newSize)
{
	if (newSize > capacity)
	{
		T* newData = new T[newSize];
		memcpy(newData, data, sizeof(T) * size);
		delete[] data;
		data = newData;
		capacity = newSize;
	}
}
template<typename T>
void TVector<T>::compact()
{
	if (size != capacity)
	{
		capacity = size;

		T* tempData = new T[capacity];
		memcpy(tempData, data, size * sizeof(T));

		delete[] data;

		data = tempData;
	}
}
template<typename T>
void TVector<T>::pop()
{
	if (size > 0)
	{
		size -= 1;
	}
}

