//Problem 3

#include <iostream>
using namespace std;

//����������� ���� � ����������
bool IsAutomorphic(int num) 
{
	int sqrtNum = num*num;
	bool isAutomorphic = true;

	while(num) 
	{
		//��� ���������� �� ��������, ����� �� � ����������
		int j = num % 10;
		int k = sqrtNum % 10;
		if(j != k) 
		{
			isAutomorphic = false;
			break;
		}
		num/=10;
		sqrtNum/=10;
	}
	return isAutomorphic;
}

int main() 
{
	int num; 

	cout<<"num=";
	cin >> num;

	for(int index = 1; index < num; index++) 
	{
		//����������� ���� � ���������� � �� ��������� 
		if(IsAutomorphic(index))
			cout << index << endl;
	}

	return 0;
}