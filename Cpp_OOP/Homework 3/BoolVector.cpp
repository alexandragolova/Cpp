#include "BoolVector.h"
#include<string>
#include<assert.h>
#include <iostream>
using namespace std;

void BoolVector::SetData(const bool* data)
{
	size = (int)data + 1;
	this->data = new bool[size];
	//this->data = data;
}

void BoolVector::SetSize(size_t size)
{
	this->size=size;
}

BoolVector::BoolVector(const BoolVector& other)
{
	SetData(other.data);
}

BoolVector::BoolVector(const bool* data)
{
	SetData(data);
}

BoolVector::~BoolVector()
{
	delete[] data;
}

BoolVector& BoolVector::operator=(const BoolVector& other)
{
	if (this == &other) return*this;
	delete[] data;
	SetData(other.data);

	return *this;
}

bool& BoolVector::operator[](size_t index)
{
	if (index < size)
		return data[index];
}

bool BoolVector::Set(int index)
{
	if (index < size)
		data[index] = 0;
	else
		return false;
}

bool BoolVector::Clear(int index)
{
	if (index < size)
		data[index] = 0;

	else
		return false;
}


