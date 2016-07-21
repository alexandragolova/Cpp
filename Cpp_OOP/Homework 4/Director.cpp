#include "Director.h"

Director::Director() :Servant()
{
	this->Servants = new Servant[0];
}

Director::~Director()
{
	delete[] Servants;
}

double Director::CalculateMoneyForSalaries()
{
	double sum=0;

	for (int i = 0; i < this->cntServants; i++)
	{
		sum += Servants[i].GetSalary();
	}
	sum += DirectorSecretary.GetSalary();

	return sum;
}

Type Director::GetType()
{
	return Type::DirectorType;
}
