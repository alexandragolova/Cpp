#pragma once

enum Type
{
	ServantType=0,
	SecretaryType = 1,
	ProfessionalType = 2,
	ManagerType = 4,
	DirectorType = 5,
};

class Servant
{
private:
	char* Name;
	char* Address;
	char* EGN;
	double Salary;
	char* Department;

public:

	Servant();
	virtual ~Servant();
	Servant::Servant(const Servant& other);
	Servant& Servant::operator=(const Servant& right);

	char* GetName();
	void SetName(char* name);

	char* GetAddress();
	void SetAddress(char* address);

	char* GetDepartment();
	void SetDepartment(char* department);

	char* GetEGN();
	void SetEGN(char egn[10]);

	double GetSalary();
	void SetSalary(double salary);

	virtual Type GetType();
};

