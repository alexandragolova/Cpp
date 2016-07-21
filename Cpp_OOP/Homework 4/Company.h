#pragma once
#include"Servant.h"
#include"Director.h"
#include"Manager.h"
#include"Professional.h"
#include"Secretary.h"
#include"Functions.h"

class Company
{
private: 
	CompanyStandarts Standarts;
	Servant* ServantList;
public:
	Company();
	~Company();

	Servant* GetServants();
	void SetServants(Servant* servantList);

	CompanyStandarts GetCompanyStandarts();
	void SetCompanyStandarts(CompanyStandarts companyStandarts);

};

