#include "Servant.h"
#include<string>

Servant::Servant()
{
	this->Name = new char[0];
	this->Address = new char[0];
	this->Department = new char[0];
	this->EGN = new char[0];
	Salary = 0;
}

Servant::~Servant()
{
	delete[] Name;
	delete[] Address;
	delete[] EGN;
	Salary = 0;
	delete[] Department;
}

Servant& Servant::operator=(const Servant& right)
{
	if (this == &right)
		return *this;

	this->SetName(right.Name);
	this->SetAddress(right.Address);
	this->SetEGN(right.EGN);
	this->SetDepartment(right.Department);
	this->SetSalary(right.Salary);

	return *this;

}

Servant::Servant(const Servant& other)
{
	this->SetName(other.Name);
	this->SetAddress(other.Address);
	this->SetEGN(other.EGN);
	this->SetDepartment(other.Department);
	this->SetSalary(other.Salary);
}

char* Servant::GetName()
{
	return Name;
}

void Servant::SetName(char* name)
{
	size_t l = strlen(name) + 1;
	strcpy_s(Name,l, name);
}

char* Servant::GetAddress()
{
	return Address;
}

void Servant::SetAddress(char* address)
{
	size_t l = strlen(address) + 1;
	strcpy_s(Address,l, address);
}

char* Servant::GetDepartment()
{
	return Department;
}

void Servant::SetDepartment(char* department)
{
	size_t l = strlen(department) + 1;
	strcpy_s(Department,l, department);
}

char* Servant::GetEGN()
{
	return EGN;
}

void Servant::SetEGN(char* egn)
{
	size_t l = strlen(egn) + 1;
	strcpy_s(EGN, l,egn);
}

double Servant::GetSalary()
{
	return Salary;
}

void Servant::SetSalary(double salary)
{
	Salary = salary;
}

Type Servant::GetType()
{
	return Type::ServantType;
}
