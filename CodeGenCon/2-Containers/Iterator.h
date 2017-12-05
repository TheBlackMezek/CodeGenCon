#pragma once
//#include "TVector.h"


template<typename T>
class iterator
{
public:
	iterator() = delete;

	iterator(T* cont, int initialIndex)
		: container(cont), idx(initialIndex)
	{}

	iterator(const iterator<T>& other)
		: container(other.container), idx(other.idx)
	{}



	iterator<T>& operator=(const iterator<T>& other)
	{
		container = other.container;
		idx = other.idx;
	}

	bool operator==(const iterator<T>& other)
	{
		bool isSameContainer = container == other.container;
		bool isSameIdx = idx == other.idx;
		return isSameContainer && isSameIdx;
	}

	bool operator!=(const iterator<T>& other)
	{
		bool isSameContainer = container == other.container;
		bool isSameIdx = idx == other.idx;
		return !isSameContainer || !isSameIdx;
	}
	
	//T& operator*();
	//
	//T& operator++();
	//T& operator++(T);

private:
	T* container;
	int idx;

};


