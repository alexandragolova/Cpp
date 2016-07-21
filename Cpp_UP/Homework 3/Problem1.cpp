//Напишете програма, която чете от конзолата цяло положително число N, където
//2 < N < 1024 и след това прочита N числа.Намерете средно аритметичното на числата.Изведете
//всички числа по - големи от него.
#include<iostream>
using namespace std;

//Попълване елементите на масива
void InputElements(int n, int arr[])
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter num:";
		cin >> arr[i];
	}
}
//Изчисляване на средноаритметичното
int Avg(int n, int arr[])
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum / n;
}

//Извеждане на числата по-големи от средноаритметичното
void PrintNumBiggerThanAvg(int n, int avg, int arr[]){
	for (int i = 0; i < n; i++)
	{
		if (arr[i]>avg)
			cout << arr[i] << ", ";
	}
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
	avg = Avg(n, arr);
	cout << "avg=" << avg << endl;

	cout << "Numbers bigger than avg:" << endl;
	PrintNumBiggerThanAvg(n, avg, arr);

	return 0;
}