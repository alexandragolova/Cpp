#include<iostream>
#include"SortTemplate.h"
using namespace std;

int main()
{
	int option, cnt, pos,element;
	Sort<int> intArray[20];
	char ch = 'Y';

	do
	{
		cout << "----------Menu----------" << endl;
		cout << "------1.Add element-----" << endl;
		cout << "------2.Delete element--" << endl;
		cout << "------3.Show elements---" << endl;
		cout << "Select option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Count element";
			cin >> cnt;

			do
			{
				cin >> element;
				/*for (int i = 0; i < cnt; i++)
				{
					intArray[i].add(element);
				}*/
			} while (cnt < 128 && cnt>0);

			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		case 2:
			cin >> element;
			cout << "Input position";
			cin >> pos;
			
			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		default:cout << "Invalid option!" << endl;
			break;
		}

	} while (ch == 'Y' || ch == 'y');




	return 0;
}