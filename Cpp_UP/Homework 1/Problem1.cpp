//Problem 1

#include<iostream>
using namespace std;

int main()
{
	double x,y;
	bool inField;

	//Въвеждаме координатите на точката, която искаме да проверим
	cout<<"x=";
	cin>>x;
	cout<<"y=";
	cin>>y;
	if (y>=0) //y в I или II квадрант т.е.y>0
	{
		if((pow(x,2)+pow(y,2))<=4) //вътре ли е в полуокръжността ?
			inField=true;
		else inField=false;
	}
	//y в III или IV квадрант т.е. y<0
	else	
	{
		//за да е вътре в правоъгълника
		if((y>=-2 && x<1) && (y>-2 && x>=-1)) 
			inField = true;
		else inField = false;
	}
	//Извеждаме дали точката попада във фигурата */
	if(inField)
		cout<<"Yes!"<<endl;
	else cout<<"No!"<<endl;
	system("pause");
	return 0;
}