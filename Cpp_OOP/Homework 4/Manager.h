#pragma once
#include "Professional.h"
class Manager :
	public Professional
{
private:
	Servant* ServantsInDepartment;
	char* DepartmentDescription;
public:
	Manager();
	~Manager();
	char* GetServantsInDepartment();
	void SetServantsInDepartment(char* servantsInDepartment);
	Type GetType();

};

