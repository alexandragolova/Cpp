#include<iostream>
#include"Query.h"
using namespace std;

void Merge(string* arr, int left, int middle, int right)
{
	int i, j, k;
	int leftSize = middle - left + 1;
	int rightSize = right - middle;

	//Create temp arrays
	string* L = new string[leftSize];
	string* R = new string[rightSize];

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

void MergeSort(string* strArr, int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		MergeSort(strArr, left, middle);
		MergeSort(strArr, middle + 1, right);
		Merge(strArr, left, middle, right);
	}
}

int main()
{
	Query query = Query();
	int cntResults, cntQuery, cntQueries, cntStrings, cntExamples, cnt = 0;
	Enter enter;
	string queryStr, operation;

	cout << "Count examples: ";
	cin >> cntExamples;
	query.SetCntExamples(cntExamples);
	do
	{
		//Input count string in range[0, 1000000]
		do
		{
			cout << "Count strings: ";
			cin >> cntStrings;
		} while (cntStrings < 0 && cntStrings>1000000);
		query.SetCntStrings(cntStrings);

		//Input all queries for example, range[0,500000]
		do
		{
			cout << "Count queries: ";
			cin >> cntQueries;
		} while (cntQueries < 0 && cntQueries>500000);
		query.SetCntQuery(cntQueries);

		//Input strings for query
		string* queryStrings = new string[cntStrings];

		for (int i = 0; i < cntStrings; i++)
		{
			do
			{
			cout << "Input string: ";
			cin >> queryStrings[i];

			if (queryStrings[i].length() > 8)
				cout << "Invalid string! Try again :) ";
			} 
			while (queryStrings[i].length() > 8);
			
		}
		//Sort strings
		MergeSort(queryStrings, 0, cntStrings-1);
		query.SetQueryStrings(queryStrings);
		
		do {
			cout << "Input operation ENTER/QUERY: ";
			cin >> operation;

			if (operation == "ENTER")
			{
				//Input (start/end) query index
				cout << "Input ENTER: ";
				cin >> enter.startInx >> enter.endInx;
				query.SetEnter(enter);

				cntQueries--;
			}
			else if (operation == "QUERY")
			{
				cout << "Input QUERY: ";
				cin >> queryStr;
				query.SetQuery(queryStr);

				//Print query result
				query.PrintQueryResult();

				cntQueries--;
			}
			else
			{
				cout << "Invalid opration!" << endl;
			}
		} 
		while (cntQueries != 0);

		//Next example
		cnt++;

	} while (cnt <= cntExamples);

	return 0;
}