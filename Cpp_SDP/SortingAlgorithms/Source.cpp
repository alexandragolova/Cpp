#include<iostream>
using namespace std;

//Selection sort
void SelectionSort(int* arr, int size)
{
	int min;
	int index;
	for (int i = 0; i < size; i++)
	{
		min = arr[i];
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				index = j;
			}
		}
		int tmp = arr[i];
		arr[i] = min;
		arr[index] = tmp;
	}
}
//End selection sort

//Bubble sort
void BubbleSort(int* arr, int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				int x = arr[i];
				arr[i] = arr[j];
				arr[j] = x;
			}
		}
	}

}
//End bubble sort

//Insertion sort
void InsertionSort(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
//end insertion sort

//Quick sort
int Partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int partitionIndex = start;
	for (int i = start; i < end; i++)
	{
		if (arr[i] <= pivot)
		{
			int tmp = arr[i];
			arr[i] = arr[partitionIndex];
			arr[partitionIndex] = tmp;
			partitionIndex++;
		}
	}
	int tmp = arr[partitionIndex];
	arr[partitionIndex] = arr[end];
	arr[end] = tmp;

	return partitionIndex;
}

void QuickSort(int* arr, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = Partition(arr, start, end);
		QuickSort(arr, start, partitionIndex - 1);
		QuickSort(arr, partitionIndex + 1, end);
	}
}
//end quick sort

//Shell sort
void ShellSort(int* arr, int size)
{
	int j;

	for (int gap = size / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < size; ++i)
		{
			int temp = arr[i];
			for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)
			{
				arr[j] = arr[j - gap];
			}
			arr[j] = temp;
		}
	}
}
//end shell sort

//MergeSort
void Merge(int* arr, int left, int middle, int right)
{
	int i, j, k;
	int leftSize = middle - left + 1;
	int rightSize = right - middle;

	//Create temp arrays
	int* L = new int[leftSize];
	int* R = new int[rightSize];

	//Separate arr to Left and Right array
	for (i = 0; i < leftSize; i++)
		L[i] = arr[left + i];
	for (j = 0; j < rightSize; j++)
		R[j] = arr[middle + 1 + j];

	//Merge Left and Right
	i = 0;
	j = 0;
	k = left;
	while (i < leftSize && j < rightSize)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	//Copy elements of left array
	while (i < leftSize)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	//Copy elements of right array
	while (j < rightSize)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void MergeSort(int* strArr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		MergeSort(strArr, left, middle);
		MergeSort(strArr, middle + 1, right);
		Merge(strArr, left, middle, right);
	}
}
//End merge sort

void PrintArr(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << ", ";
}

int main()
{
	int arr[6] = { 101,1,3,2,4,55 };
	int size= 6;

	//SelectionSort(arr, size);
	//BubbleSort(arr, size);
	//MergeSort(arr, 0, size-1);
	//ShellSort(arr, size);
	//QuickSort(arr, 0, size-1);

	PrintArr(arr, 6);

	return 0;
}