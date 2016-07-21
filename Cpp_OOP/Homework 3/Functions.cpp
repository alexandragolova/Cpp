#include"Functions.h"
#include"BoolVector.h"
#include"DoubleVector.h"
#include <iostream>
using namespace std;

void BoolVectorOperation(BoolVector boolVector){
	int boolVectorOption;

	int index,size;
	cout << "Input index";
	cin >> index;

	cout << "Input size: ";
	cin >> size;
	bool* data = new bool[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Input bool data: ";
		cin >> data[i];
	}

	cout << "-----Choose operation----------" << endl;
	cout << "------1.Set value--------------" << endl;
	cout << "------2.Get value--------------" << endl;
	cout << "Select option: ";
	cin >> boolVectorOption;

	switch (boolVectorOption)
	{
	case 1:
		boolVector.Set(index);
		cout << "Done!";
		break;
	case 2:boolVector.Clear(index);
		cout << "Done!";
		break;
	}
}

void DoubleVectorOperation(DoubleVector firstDoubleVector, DoubleVector secondDoubleVector)
{
	int doubleVectorOption;
	int doubleSize;
	cout << "Input double vector size: ";
	cin >> doubleSize;
	double* doubleData = new double[doubleSize];

	for (size_t i = 0; i < doubleSize; i++)
	{
		cout << "Input double vector data: ";
		cin >> doubleData[i];
	}

	firstDoubleVector.SetSize(doubleSize);
	firstDoubleVector.SetData(doubleData);

	int boolSize;
	cout << "Input bool vector size: ";
	cin >> boolSize;
	double* boolData = new double[boolSize];

	for (size_t i = 0; i < boolSize; i++)
	{
		cout << "Input double vector data: ";
		cin >> boolData[i];
	}

	firstDoubleVector.SetSize(boolSize);
	firstDoubleVector.SetData(boolData);

	cout << "----------Choose operation---------" << endl;
	cout << "------1.Sum -----------------------" << endl;
	cout << "------2.Deduction------------------" << endl;
	cout << "------3.Multiplication of vectors--" << endl;
	cout << "------4.Division-------------------" << endl;
	cout << "------5.Scalar product of vectors--" << endl;

	cout << "Select option: ";
	cin >> doubleVectorOption;
	switch (doubleVectorOption)
	{
	case 1: firstDoubleVector.operator+(secondDoubleVector);
		firstDoubleVector.ShowVector();
		break;

	case 2:firstDoubleVector.operator-(secondDoubleVector);
		firstDoubleVector.ShowVector();
		break;

	case 3:
		int numMultiplication;
		cout << "Input num: ";
		cin >> numMultiplication;

		firstDoubleVector.operator*(numMultiplication);
		firstDoubleVector.ShowVector();
		break;

	case 4:
		int numDivision;
		cout << "Input num: ";
		cin >> numDivision;
		firstDoubleVector.operator/(numDivision);
		firstDoubleVector.ShowVector();
		break;

	case 5:firstDoubleVector.operator%(secondDoubleVector);
		firstDoubleVector.ShowVector();
		break;

	}
}
