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
public:
	Stack();
	Stack(int capacity);
	~Stack();
	void push(T element);
	void pop();
	T top();
	bool empty();
	void size();
};
template <class T>
Stack<T>::Stack()
{
}

template<class T>
Stack<T>::Stack(int capacity) {
	if (capacity <= 0)
		throw string("Stack's capacity must be positive");
	elements = new T[capacity];
	this->capacity = capacity;
	topElement = -1;
}

template <class T>
Stack<T>::~Stack()
{
	delete[] elements;
}

template <class T>
void Stack<T>::push(T element) {
	if (topElement == capacity)
		cout << "Stack's underlying storage is overflow";
	topElement++;
	elements[topElement] = element;
}

template <class T>
void Stack<T>::pop() {
	if (topElement == -1)
		throw string("Stack is empty");
	topElement--;
}

template <class T>
T Stack<T>::top() {
	if (topElement == -1)
		cout << "Stack is empty";
	return elements[topElement];
}

template <class T>
bool Stack<T>::empty() {
	return (topElement == -1);
}

template <class T>
void Stack<T>::size()
{
	return capacity;
}