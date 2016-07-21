#include<iostream>
#include<fstream>
#include "car.h"
#include "functions.h"

using namespace std;

void ShowCars(Car* cars, int sizeofArray)
{
	for (int i = 0; i < sizeofArray; i++)
	{
		cout << "Owner Name" << endl;
		cout << cars[i].GetOwnerName() << endl;
		cout << "Id" << endl;
		cout << cars[i].GetId() << endl;
		cout << "RegNum" << endl;
		cout << cars[i].GetRegNum() << endl;
		cout << "Type" << endl;
		cout << cars[i].GetCarType() << endl;
		cout << "Power" << endl;
		cout << cars[i].GetPower() << endl;
	}
}

int main()
{

	int n = 0, option, regNum = 1000;
	char ch = 'Y';
	const char* fileName = "db-save.dat";
	Car* arrayOfCars = new Car[n];
	Car* car = new Car;

	do
	{
		cout << "----------Menu----------------" << endl;
		cout << "------1.Add car---------------" << endl;
		cout << "------2.Generate file(txt)----" << endl;
		cout << "------3.Generate file(binary)-" << endl;
		cout << "------4.Show cars-------------" << endl;
		cout << "Select option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Count cars: " << endl;
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				do
				{
					if (regNum > 9999 || regNum < 1000)
						cout << "Invalid reg num: " << endl;

					cout << "Check register number: " << endl;
					cin >> regNum;

				} while (regNum > 9999 || regNum < 1000);

				if (IsCarExist(arrayOfCars, n, regNum))
				{
					AddCar(*car, regNum);
					
				}	
				else
				{
					cout << "Reg num exist! " << endl;
					n--;
				}
				arrayOfCars[i] = *car;
			}
			cout << "Do you want to continue?[Y/N]";
			cin >> ch;
			break;

		case 2:GenerateTxtFile(arrayOfCars, n);
			cout << "Created!" << endl;
			cout << "Do you want to continue?[Y/N] : ";
			cin >> ch;
			break;

		case 3:GenerateBinaryFile(fileName, arrayOfCars);
			cout << "Created!" << endl;
			cout << "Do you want to continue?[Y/N] : ";
			cin >> ch;
			break;

		case 4:ShowCars(arrayOfCars, n);
			cout << "Do you want to continue?[Y/N] : ";
			cin >> ch;
			break;

		default:cout << "Invalid option!" << endl;
			break;
		}

	} while (ch == 'Y' || ch == 'y');

	return 0;
}