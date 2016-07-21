#include"cookie.h"
#include"jar.h"
#include"functions.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool WriteCookieToBinary(const Cookie& cookie, const char* fileName)
{
	ofstream file(fileName, ios::out | ios::app | ios::binary);

	if (!file.is_open())
		return false;

	int nameLenght = strlen(cookie.GetName());
	file.write((const char*)&nameLenght, sizeof(nameLenght));
	file.write(cookie.GetName(), sizeof(char)*nameLenght);

	for (int i = 0; i < cookie.GetCookieCountStrings(); i++)
	{
		int cookieLenght = strlen(cookie.GetCookieStrings()[i]);
		file.write((const char*)&cookieLenght, sizeof(cookieLenght));
		file.write(cookie.GetCookieStrings()[i], sizeof(char)*cookieLenght);
	}

	return file.good();
}

bool ReadCookieFromBinary(const char* file, int position, Cookie cookie)
{
	ifstream inFile(file, ios::out | ios::binary);
	if (!inFile.is_open())
		return false;

	int size = sizeof(cookie);

	inFile.seekg(0, ios::end);
	int total = inFile.tellg();

	if (position * size >= total)
	{
		inFile.close();
		return true;
	}
	return inFile.good();
}

void AddCookieToJar(Jar jar, int cookiesCount, const char* fileName)
{
	for (int i = 0; i < cookiesCount; i++)
	{
		Cookie cookie;
		int countCookiesStrings;
		char** coockiesStrings = new char*;
		char cookieName[20];
		cin >> cookieName;
		cin >> countCookiesStrings;

		cookie.SetCookieCountStrings(countCookiesStrings);
		cookie.SetName(cookieName);
		cookie.SetCookieStrings();

		jar.AddCookie(cookie);
		WriteCookieToBinary(cookie, fileName);
	}
}

void DeleteCookieFromJar(Jar jar, Cookie cookies[], int allCookies, int pos)
{
	Cookie cookie;
	cookie = cookies[pos];
	jar.DeleteCookie(cookie);
}