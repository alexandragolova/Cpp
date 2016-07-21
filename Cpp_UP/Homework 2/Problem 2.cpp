//Напишете програма, която чете от конзолата две цели числа n, m. 
//Програмата трябва да изведе на екрана броя на числата 
//в интервала [n, m] на който сборът на делителите е просто число

#include<iostream>
using namespace std;

//Помощна функция за проверка дали числото е просто
bool IsPrime(int num)
{
	if (!(num / 2)) 
		return false;

	for (int i = 1; ++i <= num / 2;)
		if (0 == num % i) 
			return false;

	return true;
}

int main()
{
	int n, m, sum = 0, cnt = 0;

	cout << "n=";
	cin >> n;

	//Проверка на входните данни :  m > n
	do{
		cout << "m=";
		cin >> m;
	} 
	while (n > m);

	//Минаване през всички числа от n до m
	for (n; n <= m; n++)
	{
		// Изчисляване на сумата на делителите на поредното число
		for (int i = 1; i <= n; i++)
		{
			if (n%i == 0)
				sum += i;
		}
		//Проверка дали сумата е просто число и добавяне към брояча
		if (IsPrime(sum))
		{
			cnt++;
		}
	}
	
	//Извеждане на брояча
	cout << cnt<<endl;
	return 0;
}