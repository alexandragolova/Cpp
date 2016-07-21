#pragma once
#include "Servant.h"
#include"Secretary.h"
class Director :
	public Servant
{
private:
	int cntServants;
	Servant* Servants;
	Secretary DirectorSecretary;

public:
	Director();
	~Director();

	Servant* GetServants();
	void SetServants(Servant* servants);

	Secretary GetSecretary();
	void SetSecretary();

	double CalculateMoneyForSalaries();

	Type GetType();
};

