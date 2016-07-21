//�������� ��������, ����� ���� �� ��������� ��� ���� ����� n, m. 
//���������� ������ �� ������ �� ������ ���� �� ������� 
//� ��������� [n, m] �� ����� ������ �� ���������� � ������ �����

#include<iostream>
using namespace std;

//������� ������� �� �������� ���� ������� � ������
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

	//�������� �� �������� ����� :  m > n
	do{
		cout << "m=";
		cin >> m;
	} 
	while (n > m);

	//�������� ���� ������ ����� �� n �� m
	for (n; n <= m; n++)
	{
		// ����������� �� ������ �� ���������� �� ��������� �����
		for (int i = 1; i <= n; i++)
		{
			if (n%i == 0)
				sum += i;
		}
		//�������� ���� ������ � ������ ����� � �������� ��� ������
		if (IsPrime(sum))
		{
			cnt++;
		}
	}
	
	//��������� �� ������
	cout << cnt<<endl;
	return 0;
}