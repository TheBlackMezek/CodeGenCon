#pragma once

#include <assert.h>



template<typename T>
struct LinkedListNode
{
	T val;
	LinkedListNode* next;
};

template<typename T>
class TLinkedList
{
private:
	LinkedListNode<T>* head;
	size_t size;

public:
	TLinkedList();
	~TLinkedList();

	TLinkedList( TLinkedList<T>& other);
	TLinkedList<T>& operator=(TLinkedList<T>& other);

	void append(T val);
	void insert(T val, size_t idx);
	void clear();
	void erase(size_t idx);

	size_t getSize() const;
	T& at(size_t idx);
	bool empty();
	T& front();
	T& back();
	size_t count(T val);
};



template<typename T>
TLinkedList<T>::TLinkedList()
	: head(nullptr)
{
	size = 0;
}

template<typename T>
TLinkedList<T>::~TLinkedList()
{
	LinkedListNode<T>* node = head;
	LinkedListNode<T>* nextNode;

	while (node != nullptr)
	{
		nextNode = node->next;
		delete node;
		node = nextNode;
	}
}


template<typename T>
TLinkedList<T>::TLinkedList(TLinkedList<T>& other)
{
	size = other.getSize();

	if (size > 0)
	{
		LinkedListNode<T>* lastNode = new LinkedListNode<T>;
		for (int i = 0; i < size; ++i)
		{
			LinkedListNode<T>* newNode = new LinkedListNode<T>;
			newNode->val = other.at(i);
			newNode->next = nullptr;

			if (i == 0)
			{
				head = newNode;
				delete lastNode;
			}
			else
			{
				lastNode->next = newNode;
			}

			lastNode = newNode;
		}
	}
	else
	{
		head = nullptr;
	}
}

template<typename T>
TLinkedList<T>& TLinkedList<T>::operator=(TLinkedList<T>& other)
{
	clear();

	size = other.getSize();

	if (size > 0)
	{
		LinkedListNode<T>* lastNode = new LinkedListNode<T>;
		for (int i = 0; i < size; ++i)
		{
			LinkedListNode<T>* newNode = new LinkedListNode<T>;
			newNode->val = other.at(i);
			newNode->next = nullptr;

			if (i == 0)
			{
				head = newNode;
				delete lastNode;
			}
			else
			{
				lastNode->next = newNode;
			}

			lastNode = newNode;
		}
	}
	else
	{
		head = nullptr;
	}

	return *this;
}





template<typename T>
void TLinkedList<T>::append(T val)
{
	LinkedListNode<T>* newNode = new LinkedListNode<T>;
	newNode->val = val;
	newNode->next = nullptr;

	if (head == nullptr)
	{
		head = newNode;
		++size;
	}
	else
	{
		LinkedListNode<T>* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		node->next = newNode;
		++size;
	}
}

template<typename T>
void TLinkedList<T>::insert(T val, size_t idx)
{
	assert(idx <= size && "Index must be within or 1 beyond linked list");

	if (idx == size)
	{
		append(val);
	}
	else if (idx == 0)
	{
		LinkedListNode<T>* newNode = new LinkedListNode<T>;
		newNode->val = val;
		newNode->next = head;
		head = newNode;
		++size;
	}
	else
	{
		LinkedListNode<T>* newNode = new LinkedListNode<T>;
		newNode->val = val;
		newNode->next = nullptr;

		int iterator = 0;
		LinkedListNode<T>* node = head;

		while (iterator != idx-1)
		{
			node = node->next;
			++iterator;
		}

		newNode->next = node->next;
		node->next = newNode;
		++size;
	}
}

template<typename T>
void TLinkedList<T>::clear()
{
	LinkedListNode<T>* node = head;
	LinkedListNode<T>* nextNode;

	while (node != nullptr)
	{
		nextNode = node->next;
		delete node;
		node = nextNode;
	}

	head = nullptr;
	size = 0;
}

template<typename T>
void TLinkedList<T>::erase(size_t idx)
{
	assert(idx < size && "Index must be within linked list");

	if (idx == 0)
	{
		LinkedListNode<T>* node = head->next;
		delete head;
		head = node;
		--size;
	}
	else
	{
		size_t iterator = 0;
		LinkedListNode<T>* node = head;

		while (iterator != idx - 1)
		{
			node = node->next;
			++iterator;
		}

		LinkedListNode<T>* delNode = node->next;
		node->next = delNode->next;
		delete delNode;
		--size;
	}
}



template<typename T>
size_t TLinkedList<T>::getSize() const
{
	return size;
}

template<typename T>
T& TLinkedList<T>::at(size_t idx)
{
	assert(idx < size && "Index must be within linked list");

	int iterator = 0;
	LinkedListNode<T>* node = head;

	while (iterator != idx)
	{
		node = node->next;
		++iterator;
	}

	return node->val;
	
}

template<typename T>
bool TLinkedList<T>::empty()
{
	return head == nullptr;
}

template<typename T>
T& TLinkedList<T>::front()
{
	assert(size > 0 && "Linked list must have elements to get front");

	return head->val;
}

template<typename T>
T& TLinkedList<T>::back()
{
	assert(size > 0 && "Linked list must have elements to get back");

	return at(size - 1);
}

template<typename T>
size_t TLinkedList<T>::count(T val)
{
	size_t ret = 0;

	LinkedListNode<T>* node = head;
	while (node != nullptr)
	{
		if (node->val == val)
		{
			++ret;
		}
		node = node->next;
	}

	return ret;
}
