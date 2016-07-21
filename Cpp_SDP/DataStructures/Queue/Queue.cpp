#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Queue
{
private:
	T* elements;
	int capacity;
	int rear;
	int front;

public:
	Queue();
	Queue(int capacity);
	~Queue();
	void Enqueue(T element);
	T Dequeue();
	int Size();
	void Display();
	bool IsEmpty();
	bool IsFull();
};
template<class T>
Queue<T>::Queue()
{
	rear = -1;
	front = 0;
}

template<class T>
Queue<T>::~Queue()
{
	delete[] elements;
}

template<class T>
Queue<T>::Queue(int capacity)
{
	if (capacity <= 0)
		throw string("Queue's capacity must be positive");
	elements = new T[capacity];
	this->capacity = capacity;

}

template<class T>
void Queue<T>::Enqueue(T element)
{
	elements[++rear] = element;
}

template<class T>
T Queue<T>::Dequeue() {
	return elements[front++];
}

template<class T>
int Queue<T>::Size()
{
	return (rear - front + 1);
}

template<class T>
void Queue<T>::Display()
{
	if (!IsEmpty())
	{
		for (size_t i = (front+1); i < rear; i++)
		{
			cout << elements[i]<<" ";
		}
	}
}

template<class T>
bool Queue<T>::IsEmpty()
{
	return (front > rear) ? true : false;
}

template<class T>
bool Queue<T>::IsFull() {
	return (Size() >= capacity) ? true : false;
}