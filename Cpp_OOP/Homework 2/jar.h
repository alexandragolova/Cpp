#ifndef JAR
#define JAR
#include"cookie.h"

class Jar
{
private:
	char* Name;
	Cookie* list;
	int count;
	int capacity;
public:
	char* GetName();
	void SetName(const char* name);

	void AddCookie(const Cookie&);
	void DeleteCookie(const Cookie& p);
	int GetCookieByPosition(const Cookie& p);
	Cookie* GetCookies();

	void Resize(int newCapacity);
	Jar& operator= (const Jar&);
};

#endif