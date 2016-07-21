#pragma once
#include "Servant.h"
class Professional :
	public Servant
{
private :
	char* SpecialtyDescription;
public:
	Professional();
	virtual ~Professional();

	char* GetSpecialtyDescription();
	void SetSpecialtyDescription(char* SpecialtyDescription);
	
	Type GetType();
};

