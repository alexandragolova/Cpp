#include"SortTemplate.h"

template <class T>
void Sort<T>::add(T& element)
{
	if (count <= size)
	{
		list[count] = element;
		++count;
	}
}

template <class T>
void Sort<T>::remove(T& element)
{
	if (size = -1)
		return;

	
			list[i] = list[count - 1];
			--count;
			resize(size - 1);

}

template <class T>
void Sort<T>::sort()
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j<size; j++)
		{
			if (a[i]>a[j])
			{
				list = a[i];
				a[i] = a[j];
				a[j] = list;
			}
		}
	}
}

template <class T>
void Sort<T>::print()
{
	sort(list[], size);

	for (i = 0; i < size; i++)
	{
		cout << list[i] << endl;
	}
}

template <class T>
void Sort<T>::resize(int newSize)
{
	if (newSize > 128)
		return;
	T* temp = new T[newSize];
	for (int i = 0; i < count; i++)
		temp[i] = list[i];

	size = newSize;
	delete[] list;
	list = temp;
}

template <class T>
Sort<T>::Sort()
{
	list = nullptr;
	size = 0;
}

template <class T>
Sort<T>::Sort(size_t capacity)
{
	list = new T[capacity];
	size = capacity;
}

template <class T>
Sort<T>::~Sort()
{
	delete[] list;
}
