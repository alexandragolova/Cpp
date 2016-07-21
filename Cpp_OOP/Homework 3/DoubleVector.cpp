#include "DoubleVector.h"
#include<cstring>
#include<assert.h>
#include <iostream>
using namespace std;

void DoubleVector::SetData(const double* data)
{
	size = (int)data + 1;
	this->data = new double[size];
	//this->data = data;
}

void DoubleVector::SetSize(size_t size)
{
	this->size = size;
}

DoubleVector::DoubleVector(const DoubleVector& other)
{
	SetData(other.data);
}

DoubleVector::DoubleVector(const double* data)
{
	SetData(data);
}

DoubleVector::~DoubleVector()
{
	delete[] data;
}

void DoubleVector::Resize(int newSize)
{
	double* temp = new double[newSize];
	for (int i = 0; i < size; i++)
		temp[i] = data[i];

	size = newSize;
	delete[] data;
	data = temp;
}

double& DoubleVector::operator[](int index)const
{
	assert(index < size);
	return data[index];
}

DoubleVector& DoubleVector::operator=(const DoubleVector& other)
{
	if (this == &other) return*this;
	delete[] data;
	SetData(other.data);

	return *this;
}

DoubleVector& DoubleVector::operator+=(const DoubleVector& other)
{
	if (size < other.size)
		this->Resize(other.size);

	for (int i = 0; i < other.size; i++)
	{
		data[i] += other[i];
	}

	return *this;
}

DoubleVector& DoubleVector::operator+(const DoubleVector& other)const
{
	DoubleVector result = *this;
	result += other;
	return result;
}

DoubleVector& DoubleVector::operator-=(const DoubleVector& other)
{
	if (size < other.size)
		this->Resize(other.size);

	for (int i = 0; i < other.size; i++)
	{
		data[i] -= other[i];
	}

	return *this;
}

DoubleVector& DoubleVector::operator-(const DoubleVector& other)const
{
	DoubleVector result = *this;
	result -= other;
	return result;
}

DoubleVector& DoubleVector::operator*=(const double& other)
{
	for (int i = 0; i < this->size; i++)
	{
		data[i] *= other;
	}

	return *this;
}

DoubleVector& DoubleVector::operator*(const double& other)const
{
	DoubleVector result = *this;
	result *= other;
	return result;
}

DoubleVector& DoubleVector::operator/=(const double& other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (other != 0)
			data[i] /= other;
		else
			data[i] = 0;
	}
	return *this;
}

DoubleVector& DoubleVector::operator/(const double& other)const
{
	DoubleVector result = *this;
	result /= other;
	return result;
}

int DoubleVector ::operator% (const DoubleVector& other)const
{
	int sum = 0;

	for (int i = 0; i < other.size; i++)
	{
		data[i] *= other[i];
		sum += data[i];
	}

	return sum;

}

void DoubleVector::ShowVector()const
{
	cout << "size :" << size << endl;
	cout << "data{ ";
	for (size_t i = 0; i < size; i++)
	{
		cout << data[i] << ", ";
	}
	cout << " } ";
}

