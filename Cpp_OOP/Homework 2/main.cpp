#include"cookie.h"
#include"jar.h"
#include"functions.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	int option, countCookies;
	char jarName[20];
	char ch = 'Y';
	const char* fileName = "JarOfCookies.dat";
	Jar jar;

	cout << "Jar name:";
	cin >> jarName;
	jar.SetName(jarName);

	do
	{
		cout << "----------Menu--------------------" << endl;
		cout << "------1.Add cookie to jar---------" << endl;
		cout << "------2.Delete cookie (by index)--" << endl;
		cout << "Select option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Count cookies:";
			cin >> countCookies;

			AddCookieToJar(jar, countCookies, fileName);

			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		case 2:
			char d = 'Y';
			int pos;
			cout << "Position:";
			cin >> pos;
			//TODO:
			ReadCookieFromBinary(fileName,pos,);
			cout << "Do you want to delete cookie?[Y/N]";
			cin >> d;
			if (d == 'y' || d == 'Y')
			{
				DeleteCookieFromJar(jar, jar.GetCookies(), countCookies, pos);
			}

			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		default:cout << "Invalid option!" << endl;
			break;
		}

	} while (ch == 'Y' || ch == 'y');


	return 0;
}