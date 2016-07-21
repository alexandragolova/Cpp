#pragma once

struct CompanyStandarts
{
	int cntDepartments;
	int cntSpecialties;
	int cntServants;
	int cntProfessionalists;
	int cntDirectors;

};

bool IsRealCompany(CompanyStandarts companyStandarts, CompanyStandarts inputStandarts);
