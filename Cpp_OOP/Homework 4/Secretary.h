#pragma once
#include "Servant.h"
class Secretary :
	public Servant
{
private :
	int cntLanguages;
	char** ListLanguages;
public:
	Secretary();
	virtual ~Secretary();

	char** GetLanguages();
	void SetLanguages();

	Type GetType();
};

