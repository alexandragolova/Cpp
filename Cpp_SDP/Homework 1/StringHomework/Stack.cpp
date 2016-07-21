#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	T* elements;
	int topElement;
	int capacity;
	int elementsCount;
public:
	Stack(int capacity);
	~Stack();
	void push(T element);
	void pop();
	T top() const;
	bool empty();
	int size();
	void resize(size_t newCapacity);
	int count();
};
template<class T>
void Stack<T>::resize(size_t newCapacity)
{
	T* temp = new T[newCapacity];
	for (int i = 0; i < this->capacity; i++)
		temp[i] = elements[i];

	capacity = newCapacity;
	delete[] elements;
	elements = temp;
}

template<class T>
Stack<T>::Stack(int capacity) {
	if (capacity <= 0)
		throw string("Stack's capacity must be positive");
	elements = new T[capacity];
	this->capacity = capacity;
	topElement = -1;
	elementsCount = 0;
}

template <class T>
Stack<T>::~Stack()
{
	/*try {
		delete[] elements;
	}
	catch {}*/
}

template <class T>
void Stack<T>::push(T element) {

	if (topElement == capacity)
		resize(capacity * 2);

	topElement++;
	elementsCount++;
	elements[topElement] = element;
}

template <class T>
void Stack<T>::pop() {
	if (topElement == -1)
		throw string("Stack is empty");
	elementsCount--;
	topElement--;
}

template <class T>
T Stack<T>::top() const {
	if (topElement == -1)
		cout << "Stack is empty";
	return elements[topElement];
}

template <class T>
bool Stack<T>::empty() {
	return (topElement == -1);
}

template <class T>
int Stack<T>::size()
{
	return capacity;
}

template <class T>
int Stack<T>::count()
{
	return elementsCount;
}