#include "Manager.h"
#include<string>

Manager::Manager() :Professional()
{
	DepartmentDescription = nullptr;
}

Manager::~Manager()
{
	delete[] ServantsInDepartment;
}
Type Manager::GetType()
{
	return Type::ManagerType;
}
