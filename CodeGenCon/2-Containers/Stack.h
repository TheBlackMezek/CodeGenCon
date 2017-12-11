#pragma once

#include "TVector.h"

template<typename T>
class Stack
{
private:
	TVector<T> vector;

public:
	bool empty();
	int size();
	T pop();

	void push(T elm);
	T top();

};



template<typename T>
bool Stack<T>::empty()
{
	return vector.empty();
}

template<typename T>
int Stack<T>::size()
{
	return vector.getSize();
}

template<typename T>
T Stack<T>::pop()
{
	assert(vector.getSize() > 0 && "Stack must contain an element to pop");

	T ret = vector[vector.getSize() - 1];
	vector.erase(vector.getSize() - 1);
	return ret;
}

template<typename T>
void Stack<T>::push(T elm)
{
	vector.append(elm);
}

template<typename T>
T Stack<T>::top()
{
	assert(vector.getSize() > 0 && "Stack must contain an element to read");

	return vector[vector.getSize() - 1];
}
