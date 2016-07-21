#ifndef COOKIE
#define COOKIE

class Cookie
{
private:
	char* Name;
	char** ListCookieStrings;
	int countStrings;
public:
	void SetName(const char* name);
	char* GetName() const;

	char** GetCookieStrings()const;
	void SetCookieStrings();

	void SetCookieCountStrings(int count);
	int GetCookieCountStrings()const;

	Cookie& operator= (const Cookie&);
	bool operator == (const Cookie& right)const;

};

#endif