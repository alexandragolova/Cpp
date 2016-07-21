#include "Company.h"
#include "Functions.h"
#include<iostream>
using namespace std;

Company::Company()
{
	Standarts.cntDepartments = 0;
	Standarts.cntProfessionalists = 0;
	Standarts.cntServants = 0;
	Standarts.cntSpecialties = 0;
	Standarts.cntDirectors = 0;
	ServantList = new Servant[0];
}

Company::~Company()
{
	delete[] ServantList;
	Standarts.cntProfessionalists = 0;
	Standarts.cntServants = 0;
	Standarts.cntDepartments = 0;
	Standarts.cntSpecialties = 0;
	Standarts.cntDirectors = 0;
}

Servant* Company::GetServants(){

	return ServantList;
}

void Company::SetServants(Servant* servantList){

	ServantList = servantList;
}

CompanyStandarts Company::GetCompanyStandarts()
{
	return Standarts;
}

void Company::SetCompanyStandarts(CompanyStandarts companyStandarts)
{
	Standarts.cntDepartments = companyStandarts.cntDepartments;
	Standarts.cntProfessionalists = companyStandarts.cntProfessionalists;
	Standarts.cntServants = companyStandarts.cntServants;
	Standarts.cntSpecialties = companyStandarts.cntSpecialties;
}