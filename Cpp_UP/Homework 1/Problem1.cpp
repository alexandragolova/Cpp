//Problem 1

#include<iostream>
using namespace std;

int main()
{
	double x,y;
	bool inField;

	//��������� ������������ �� �������, ����� ������ �� ��������
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	if (y>=0) //y � I ��� II �������� �.�.y>0
	{
		if((pow(x,2)+pow(y,2))<=4) //����� �� � � ��������������� ?
			inField=true;
		else inField=false;
	}
	//y � III ��� IV �������� �.�. y<0
	else	
	{
		//�� �� � ����� � �������������
		if((y>=-2 && x<1) && (y>-2 && x>=-1)) 
			inField = true;
		else inField = false;
	}
	//��������� ���� ������� ������ ��� �������� */
	if(inField)
		cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
	system("pause");
	return 0;
}