/*�������� ��������, ����� ���� �� ��������� ���� ����� n. ���� ���� ������� �� ������ n-
��� ���� �� ���������� �� ������.*/

#include<iostream>
using namespace std;

//������� ������� �� �������� �� ��������� 
int factorial(int num) {
	int fact;

	if(num <= 1) 
		return 1;

	fact = num * factorial(num - 1);
	return fact;
}

int main()
{
	int n,a,b,c,i=0,coefficient;

	cout<<"n= ";
	cin>>n;

	while (i<=n)
	{
		for (int x = n; x >=0; x--)	
		{
			//��������� �� ��������� � ����������
			for (int j = n; j > i; j--)
				cout << " ";
			a=x;	

			for (int y = i,z=0; y >=0,z<=i; y--,z++)
			{	
				b=y;
				c=z;

				//����������� �� �������� ������� �� ���������� 
				coefficient=(factorial(n))/(factorial(a)*factorial(b)*factorial(c));
				cout<<coefficient<<" ";
			}
			cout<<endl;
			i++	;	
		}
	}
	return 0;
}