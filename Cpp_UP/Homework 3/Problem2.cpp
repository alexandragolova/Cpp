//Напишете програма която чете от конзолата цяло число N, където
//2 < N < 1024 и след това прочита N числа.Намерете стартовия индекс и дължината на най -
//дългата площадка в масива.
#include<iostream>
using namespace std;

//Популване елементите на масива
void InputElements(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << "Index: " << i << ", Enter num:";
		cin >> arr[i];
	}
}
//Намиране на най-дългата площадка и стартовия индекс
void MaxField(int n, int arr[])
{
	int max = 0, count = 0, startIndex = 0;
	for (int i = 0; i <= n; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
		}
		else
		{
			if (max < count)
			{
				max = count;
				startIndex = i - max;
			}
			count = 0;
		}
	}
	cout << "Start index: " << startIndex << endl;
	cout << "Max lenght in array: " << max + 1;
}

int main()
{
	int n, arr[1024], sum = 0, avg;

	//Проверка на входните данни
	do
	{
		cout << "N=";
		cin >> n;
	} while (n<2 || n>1024);

	InputElements(n, arr);
	MaxField(n, arr);

	return 0;
}