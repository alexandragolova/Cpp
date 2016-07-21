#include "car.h"
#include<cstring>

int Car::GetPower(){
	switch (Type)
	{
	case 0:
		return 670;
	case 1: 
		return 503;
	case 2: 
		return 740;
	case 3: 
		return 1020;
	default:
		return 0;
	}
}

CarType Car::GetCarType()
{
	switch (Type)
	{
	case 0:
		return CarType::LambordginiMurcielago;
	case 1: 
		return CarType::MercedesAMG;
	case 2: 
		return CarType::PaganiZondaR;
	case 3:
		return CarType::BugattiVeyron;
	default:
		return CarType::None;

	}
}

int Car::GetId(){
	return ID;
}

int Car::GetRegNum(){
	return RegNum;
}

char* Car::GetOwnerName()
{
	return OwnerName;
}

void Car::SetCarType(int type){
	switch (type)
	{
	case 0:
		Type = CarType::LambordginiMurcielago;
		break;
	case 1:
		Type = CarType::MercedesAMG;
		break;
	case 2:
		Type = CarType::PaganiZondaR;
		break;
	case 3:
		Type = CarType::BugattiVeyron;
		break;
	default:
		break;
	}
}

void Car::SetId(int id){
	ID = id;
}

void Car::SetRegNum(int regNum){
	RegNum = regNum;
}

void Car::SetOwnerName(char* ownerName){
	strcpy_s(OwnerName,23,ownerName);
}

