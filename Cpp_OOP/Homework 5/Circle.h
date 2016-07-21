#pragma once
#include "Figure.h"
#include "Group.h"
using namespace std;

class Circle : public Figure,public Group
{
public:
	double Radius;
	double X;
	double Y;

public:
	Circle();
	~Circle();

	bool Input();
	bool Read(istream & in);
	bool Write(ostream & out);
	void Print()const;
	const char* GetFigureType();
	void TranslationFigure(Circle& figure);

	bool CheckPoint(Point point);
	void GetAbsCoordinate();
};
