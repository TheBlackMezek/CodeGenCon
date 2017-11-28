#pragma once


class IntVector
{
private:
	int* data;
	size_t capacity;
	size_t size;

	bool grow(size_t minSize);

public:
	IntVector();
	~IntVector();

	int& operator[](const size_t i);
	const int& operator[](const size_t i) const;

	int& at(size_t idx);
	void append(int val);
	int* c_ptr() const;
	size_t getCapacity() const;
	size_t getSize() const;
	bool empty() const;
	int front() const;
	int back() const;
	void clear();
	void erase(size_t i);
	int count(int num) const;
	void insert(int elm, size_t idx);
	void reserve(size_t newSize);
	void compact();

};



