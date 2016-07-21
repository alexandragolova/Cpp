#include<iostream>
#include"BoolVector.h"
#include"DoubleVector.h"
#include"Functions.h"
using namespace std;

int main()
{
	int mainMenuOption,doubleVectorOption;
	char ch = 'Y';
	char d = 'Y';

	DoubleVector firstVector = DoubleVector();
	DoubleVector secondVector = DoubleVector();
	BoolVector boolVector = BoolVector();

	do
	{
		cout << "----------Menu-----------" << endl;
		cout << "------1.Double vector----" << endl;
		cout << "------2.Bool vector------" << endl;
		cout << "Select option: ";
		cin >> mainMenuOption;

		switch (mainMenuOption)
		{
		case 1:

			DoubleVectorOperation(firstVector, secondVector);

			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		case 2:
			
			BoolVectorOperation(boolVector);
			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		default:cout << "Invalid option!" << endl;
			break;
		}

	} while (ch == 'Y' || ch == 'y');

	return 0;
}
	