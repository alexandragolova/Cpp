#include<iostream>
#include "Servant.h"
#include "Secretary.h"
#include "Manager.h"
#include "Professional.h"
#include "Director.h"
#include"Functions.h"
using namespace std;

int main()
{
	CompanyStandarts companyStandarts,inputStandatrs;
	companyStandarts.cntDepartments = 0;
	companyStandarts.cntDirectors = 0;
	companyStandarts.cntProfessionalists = 0;
	companyStandarts.cntServants = 0;
	companyStandarts.cntSpecialties = 0;

	int n, ch;

	cout << "Input company standarts";
	cin >> inputStandatrs.cntDepartments;
	cin >> inputStandatrs.cntDirectors;
	cin >> inputStandatrs.cntProfessionalists;
	cin >> inputStandatrs.cntServants;
	cin >> inputStandatrs.cntSpecialties;

	cout << "Input count servant";
	cin >> n;

	Servant** servants = new Servant*[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Choose servant position";
		cout << "-----1.Servant---------";
		cout << "-----2.Secretary-------";
		cout << "-----3.Manager---------";
		cout << "-----4.Professional----";
		cout << "-----5.Director--------";
		do
		{
			cin >> ch;
		} while (ch > 5 && ch < 1);

		switch (ch)
		{
		case 1:
			servants[i] = new Servant();
			companyStandarts.cntServants += 1;
		case 2:
			servants[i] = new Secretary();
			companyStandarts.cntServants += 1;

		case 3:
			servants[i] = new Manager();
			companyStandarts.cntProfessionalists += 1;
		case 4:
			servants[i] = new Professional();
			companyStandarts.cntProfessionalists += 1;
		case 5:
			servants[i] = new Director();
			companyStandarts.cntDirectors += 1;

		default:
			break;
		}
	}


	cout << "Is real company? : "<<IsRealCompany(companyStandarts, inputStandatrs);



	return 0;
}
