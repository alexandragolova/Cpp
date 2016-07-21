#include "Secretary.h"
#include<string>
#include<iostream>
using namespace std;

Secretary::Secretary() :Servant()
{
	cntLanguages = 0;
	ListLanguages = nullptr;
}

Secretary::~Secretary()
{
	delete[] ListLanguages;
}

void Secretary::SetLanguages()
{
	int countLanguages = this->cntLanguages;
	for (int i = 0; i < countLanguages; i++)
	{
		char* str = new char[0];
		cin>> str;
		strcpy_s(ListLanguages[i], sizeof(ListLanguages[i]), str);
	}
}

char** Secretary::GetLanguages()
{
	return ListLanguages;
}

Type Secretary::GetType()
{
	return Type::SecretaryType;
}
