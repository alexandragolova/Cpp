#include"cookie.h"
#include<string>
#include<fstream>
using namespace std;

void Cookie::SetName(const char* name)
{
	delete[] this->Name;
	size_t l = strlen(name) + 1;
	this->Name = new char[l];
	strcpy_s(this->Name, l, name);
}

char* Cookie::GetName() const
{
	return Name;
}

void Cookie::SetCookieStrings()
{
	int countCookieStrings = this->countStrings;
	for (int i = 0; i < countCookieStrings; i++)
	{
		const char* str = "cookie" + (char)i;
		strcpy_s(ListCookieStrings[i], sizeof(ListCookieStrings[i]), str);
	}
}

char** Cookie::GetCookieStrings()const
{
	char** cookieStrings = new char*[];
	for (int i = 0; i < countStrings; i++)
	{
		cookieStrings[i] = ListCookieStrings[i];
	}

	return cookieStrings;
}

int Cookie::GetCookieCountStrings()const
{
	return countStrings;
}

void Cookie::SetCookieCountStrings(int count)
{
	countStrings = count;

}

Cookie& Cookie::operator=(const Cookie& right)
{
	if (this == &right) return *this;
	this->SetName(right.Name);

	return *this;
}

bool Cookie::operator == (const Cookie& right)const
{
	return strcmp(Name, right.Name) == 0;
}
