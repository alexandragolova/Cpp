#include "Professional.h"
#include<string>

Professional::Professional() :Servant()
{
	this->SpecialtyDescription = new char[0];
}

Professional::~Professional()
{
	delete[] SpecialtyDescription;
}


char* Professional::GetSpecialtyDescription()
{
	return SpecialtyDescription;
}

void Professional::SetSpecialtyDescription(char* specialtyDescription)
{
	size_t l = strlen(specialtyDescription) + 1;
	strcpy_s(SpecialtyDescription, l,specialtyDescription);
}

Type Professional::GetType()
{
	return Type::ProfessionalType;
}
