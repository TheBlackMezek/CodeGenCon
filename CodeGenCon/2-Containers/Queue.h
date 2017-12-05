#pragma once

#include "TLinkedList.h"



template<typename T>
class Queue
{
private:
	TLinkedList<T> list;

public:
	//front is the list's head

	bool empty();
	int size();
	void push(T elm);
	T pop();
	//empty
	//size
	//push
	//pop
	// - return the thing that was popped

	T front();
	T back();
	//front
	// - access the front element
	//back
	// - access the back element

};



template<typename T>
bool Queue<T>::empty()
{
	return list.empty();
}

template<typename T>
int Queue<T>::size()
{
	return list.getSize();
}

template<typename T>
void Queue<T>::push(T elm)
{
	list.append(elm);
}

template<typename T>
T Queue<T>::pop()
{
	T ret = list.front();
	list.erase(0);
	return ret;
}

template<typename T>
T Queue<T>::front()
{
	return list.front();
}

template<typename T>
T Queue<T>::back()
{
	return list.back();
}
