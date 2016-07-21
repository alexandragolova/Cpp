#include<iostream>
#include"Functions.h"
#include"Servant.h"
using namespace std;

bool IsRealCompany(CompanyStandarts companyStandarts, CompanyStandarts inputStandarts)
{
	bool situation;
	situation = (companyStandarts.cntDepartments > inputStandarts.cntDepartments) ? true : false;
	situation = (companyStandarts.cntSpecialties > inputStandarts.cntSpecialties) ? true : false;
	situation = (companyStandarts.cntServants > inputStandarts.cntServants) ? true : false;
	situation = (companyStandarts.cntProfessionalists > inputStandarts.cntProfessionalists) ? true : false;
	situation = (companyStandarts.cntDirectors > inputStandarts.cntDirectors) ? true : false;

	return situation;
}

void SortServantsSalary(Servant* servants, int cntServants)
{
	Servant servant;

	for (int i = 0; i < cntServants; i++)
	{
		for (int j = 0; j < cntServants; j++)
		{
			if (servants[j].GetSalary() > servants[j + 1].GetSalary())
			{
				servant = servants[j];
				servants[j] = servants[j + 1];
				servants[j + 1] = servant;
			}
		}
	}
}

void ChooseTeam(Servant* servants, CompanyStandarts standarts, CompanyStandarts inputStandarts)
{
	int minSalary = 0;
	int cntServants = standarts.cntDepartments + standarts.cntDirectors + standarts.cntProfessionalists + standarts.cntServants + standarts.cntSpecialties;
	Servant* servantsList = new Servant[standarts.cntServants];
	Servant* professionalistsLists = new Servant[standarts.cntProfessionalists];
	Servant* directorsList = new Servant[standarts.cntDirectors];

	for (int i = 0; i < standarts.cntServants; i++)
	{

		switch (servants[i].GetType())
		{
		case Type::ServantType:


			for (int j = 0; j < cntServants; j++)
			{
				for (size_t i = 0; i < inputStandarts.cntServants;)
				{
					if (servants[i].GetType() == Type::ServantType)
					{
						servantsList[i] = servantsList[i];
						i++;
					}
				}

			}
			SortServantsSalary(servantsList, standarts.cntServants);
			for (int i = 0; i < inputStandarts.cntServants; i++)
			{
				minSalary += servantsList[i].GetSalary();
			}
			break;
		case ProfessionalType:


			for (int j = 0; j < standarts.cntProfessionalists; j++)
			{
				for (size_t i = 0; i < inputStandarts.cntProfessionalists;)
				{
					if (servants[i].GetType() == Type::ProfessionalType)
					{
						servantsList[i] = servantsList[i];
						i++;
					}
				}

			}
			SortServantsSalary(professionalistsLists, standarts.cntProfessionalists);
			for (int i = 0; i < inputStandarts.cntProfessionalists; i++)
			{
				minSalary += professionalistsLists[i].GetSalary();
			}
			break;

		case DirectorType:

			for (int j = 0; j < standarts.cntDirectors; j++)
			{
				for (size_t i = 0; i < inputStandarts.cntDirectors;)
				{
					if (servants[i].GetType() == Type::DirectorType)
					{
						directorsList[i] = servantsList[i];
						i++;
					}
				}
			}
			SortServantsSalary(directorsList, standarts.cntDirectors);

			for (int i = 0; i < inputStandarts.cntDirectors; i++)
			{
				minSalary += directorsList[i].GetSalary();
			}
			break;
		default:
			break;
		}


	}
	cout << "Team with min salary:";
	cout << minSalary;
}

