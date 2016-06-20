#include "vector.h"

#include <iostream>

Vector::Vector()
{
	cap = 4;
	size = 0;
	arr = new int[cap];
}

Vector::~Vector()
{
	delete[] arr;
}

void Vector::copy(Vector const& rs)
{
	size = rs.size;
	cap = rs.cap;
	delete[] arr;
	arr = new int[cap];
	for (int i = 0; i < size; i++)
		arr[i] = rs.arr[i];
}

Vector Vector::operator=(Vector const& rs)
{
	if (this != &rs)
		copy(rs);
	return *this;
}

Vector::Vector(Vector const& rs)
{
	cap = rs.cap;
	size = rs.size;
	arr = new int[cap];
	for (int i = 0; i < size; i++)
		arr[i] = rs.arr[i];
}

void Vector::resize()
{
	int oldCap = cap;
	cap = oldCap * 1.5;
	int* newArr = new int[cap];
	for (int i = 0; i < size; i++)
		newArr[i] = arr[i];
	delete[] arr;
	arr = newArr;
}

void Vector::insert(int pos, int arg)
{
	if (size == cap - 1)
		resize();
	if (pos >= 0 && pos <= size)
	{
		for (int i = size; i > pos; i--)
			arr[i] = arr[i - 1];
		arr[pos] = arg;
		size++;
	}
}

void Vector::print() const
{
	std::cout << "cap:" << cap << " size:" << size << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << std::endl;
}
