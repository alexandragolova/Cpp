#include<iostream>
#include<fstream>
#include "functions.h"
using namespace std;

void AddCar(Car& car, int regNum)
{
	char ownerName[23];
	int id;
	int type;

	car.SetRegNum(regNum);
	do
	{
		cout << "Owner name: " << endl;
		cin >> ownerName;
	} while (strlen(ownerName) > 23);

	car.SetOwnerName(ownerName);

	cout << "Car id: " << endl;
	cin >> id;
	car.SetId(id);

	do
	{
		cout << "Select car type:" << endl;
		cout << "0 - Lambordgini Murcielago" << endl;
		cout << "1 - Mercedes-AMG" << endl;
		cout << "2 - Pagani Zonda R" << endl;
		cout << "3 - Bugatti Veyron" << endl;
		cout << "Select type:";
		cin >> type;
	} while (type > 3 || type < 0);

	car.SetCarType(type);
}

bool IsCarExist(Car cars[], int sizeArray, int regNum)
{

	for (int i = 0; i < sizeArray; i++)
	{
		if (regNum == cars[i].GetRegNum())
			return false;
	}
	return true;
}

bool IsOwnerExist(Car cars[], int sizeArray, char* owner)
{
	for (int i = 0; i < sizeArray; i++)
	{
		if (!strcmp(owner, cars[i].GetOwnerName()))
			return false;
	}
	return true;
}

int GetAvgPower(Car cars[], int sizeArray)
{
	int power = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		power += cars[i].GetPower();
	}
	return power / sizeArray;
}

char* TheMostPopularCar(Car cars[], int sizeArray)
{

	int cnt[4] = { 0, 0, 0, 0 }, max = 0;
	int typeNum = 0;
	char* result = new char[30];

	for (int i = 0; i < sizeArray; i++)
	{
		if (cars[i].GetCarType() == CarType::LambordginiMurcielago)
			cnt[0] += 1;
		if (cars[i].GetCarType() == CarType::MercedesAMG)
			cnt[1] += 1;
		if (cars[i].GetCarType() == CarType::PaganiZondaR)
			cnt[2] += 1;
		if (cars[i].GetCarType() == CarType::BugattiVeyron)
			cnt[3] += 1;
	}
	for (int i = 0; i < 4; i++)
	{
		if (max < cnt[i])
		{
			max = cnt[i];
			typeNum = i;
		}
	}
	char* temp;
	switch (typeNum)
	{
	case 0:
		temp = "Lambordgini Murcielago";
		strcpy_s(result, strlen(result), temp);
		return result;
	case 1:
		temp = "Mercedes AMG";
		strcpy_s(result, strlen(result), temp);
		return result;
	case 2:
		temp = "Pagani Zonda R";
		strcpy_s(result, strlen(result), temp);
		return result;
	case 3:
		temp = "Bugatti Veyron";
		strcpy_s(result, strlen(result), temp);
		return result;
	default: return "None";
	}

}

int CountCarByOwner(Car cars[], int sizeArray, char* ownerName)
{
	int cntCar = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		if (strcmp(ownerName, cars[i].GetOwnerName()))
			cntCar += 1;
	}
	return cntCar;
}

Car* CarByOwner(Car cars[], int sizeArray, char* ownerName)
{
	int cntCar = CountCarByOwner(cars, sizeArray, ownerName);
	int cnt = 0;

	Car* ownerCars = new Car[cntCar];

	for (int i = 0; i < sizeArray; i++)
	{
		if (!strcmp(ownerName, cars[i].GetOwnerName()))
		{
			ownerCars[cnt].SetCarType(cars[i].GetCarType());
			ownerCars[cnt].SetId(cars[i].GetId());
			ownerCars[cnt].SetOwnerName(cars[i].GetOwnerName());
			ownerCars[cnt].SetRegNum(cars[i].GetRegNum());
			cnt += 1;
		}
	}
	return ownerCars;
}

char** OwnerList(Car cars[], int sizeArray)
{
	int cntOwners = 0;
	char** owners = new char*;

	for (int i = 0; i < sizeArray; i++)
	{
		if (!IsOwnerExist(cars, sizeArray, cars[i].GetOwnerName()))
		{
			owners[cntOwners] = cars[i].GetOwnerName();
			cntOwners += 1;
		}
	}

	return owners;
}

int OwnerPower(Car cars[], int sizeArray, char* ownerName)
{
	int power = 0;
	for (int i = 0; i < sizeArray; i++)
	{
		if (!strcmp(ownerName, cars[i].GetOwnerName()))
			power += cars[i].GetPower();
	}
	return power;
}

void GenerateTxtFile(Car cars[], int size)
{
	char** owners = OwnerList(cars, size);
	ofstream report;

	report.open("cars-report.txt");
	report << "The most popular car is :" << endl;
	report << TheMostPopularCar(cars, size) << endl;


	report << "AvgPower :" << endl;
	report << GetAvgPower(cars, size) << endl;

	report << "Owners/Cars: " << endl;
	for (int i = 0; i < size; i++)
	{
		report << "--------------"<<i<<"---------------" << endl;
		report << "Owner: " << endl;
		report << owners[i] << endl;
		report << "Avg power: " << endl;
		report << OwnerPower(cars, size, owners[i]) << endl;
		report << "-------------------------------" << endl;
	}

	report.close();
}

bool GenerateBinaryFile(const char* file, Car cars[])
{
	ofstream outFile(file, ios::out | ios::binary | ios::app);
	if (!outFile.is_open())
		return false;
	int size = sizeof(cars);

	outFile.write(reinterpret_cast <const char*>(&cars), size);

	outFile.close();
	return true;
}

bool IsFileExist(const char *file)
{
	ifstream newfile(file, ios::in | ios::binary | ios::ate);
	if (newfile.is_open())
	{
		newfile.close();
		return true;
	}
	else return false;
}

