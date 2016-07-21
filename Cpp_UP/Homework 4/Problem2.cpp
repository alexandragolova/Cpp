#include<iostream>
#include <string>
#include <cctype>
using namespace std;


//Въвеждане на идентификатор
void InputIdentifier(char identifier[])
{
	cout << "Input:";
	cin >> identifier;
}

//Валидация на въведения идентификатор
bool IsValid(char identifier[])
{
	int sizeOfArray = strlen(identifier);

	for (int i = 0; i < sizeOfArray; i++)
	{
		//Проверка за първия символ /латинска буква или "_"/
		if ((i = 0) && ((int)identifier[i]<65 || (int)identifier[i]>90 ||
			(int)identifier[i]<95 || (int)identifier[i]>95 ||
			(int)identifier[i]<97 || (int)identifier[i]>122))
			return false;

			//Проверка зз останалите символи /латинска буква, "_" или число/
		if ((i >0) && ((int)identifier[i]<48 || (int)identifier[i]>57 ||
			(int)identifier[i]<65 || (int)identifier[i]>90 ||
			(int)identifier[i]<95 || (int)identifier[i]>95 ||
			(int)identifier[i]<97 || (int)identifier[i]>122))
			return false;
		else return true;
	}
}
//Промяна на първия елемент от масива > главна буква
void IdenficatorsToUpper(char * str)
{
	//Проверка дали първия елемент е "_"
	if ((int)str[0] != 95)
	{
		str[0] = toupper(str[0]);
		cout << "str:" << str;
	}
	else cout << "str:" << str;
}

int main()
{
	char identifier[100];

	InputIdentifier(identifier);

	if (IsValid(identifier))
		IdenficatorsToUpper(identifier);
	else cout << "Identifier is not valid";

	return 0;
}