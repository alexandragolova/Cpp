#include"cookie.h"
#include"jar.h"
#include<string>

void Jar::SetName(const char* name)
{
	int l = strlen(this->Name) + 1;
	delete[] this->Name;
	this->Name = new char[l];
	strcpy_s(this->Name, l, name);
}

char* Jar::GetName()
{
	return Name;
}

void Jar::AddCookie(const Cookie& p)
{
	if (count == capacity)
	{
		Resize(capacity * 2);
	}
	else
	{
		list[count] = p;
		++count;
	}
}

void Jar::DeleteCookie(const Cookie& p)
{
	int pos = GetCookieByPosition(p);
	if (pos = -1)
		return;

	list[pos] = list[count - 1];
	--count;

	if (2 * count < capacity)
		Resize(capacity / 2);
}

void Jar::Resize(int newCapacity)
{
	Cookie* temp = new Cookie[newCapacity];
	for (int i = 0; i < count; i++)
		temp[i] = list[i];

	capacity = newCapacity;
	delete[] list;
	list = temp;
}

int Jar::GetCookieByPosition(const Cookie& p)
{
	for (int i = 0; i < count; i++)
	{
		if (list[i] == p)
			return i;
	}
	return -1;

}

Cookie* Jar::GetCookies()
{
	Cookie* cookiesList = new Cookie[count];

	for (int i = 0; i < count; i++)
	{
		cookiesList[i] = list[i];
	}

	return cookiesList;
}

Jar& Jar::operator=(const Jar& right)
{
	if (this == &right)
		return *this;

	this->SetName(right.Name);

	delete[] this->list;

	this->count = right.count;
	this->capacity = right.capacity;
	this->list = new Cookie[capacity];

	for (int i = 0; i < count; i++)
	{
		this->list[i] = right.list[i];
	}

	return *this;

}
