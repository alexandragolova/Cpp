#pragma once
#include "Figure.h"
#include "Group.h"

class Triangle : public Figure, public Group
{
public:
	Point A;
	Point B;
	Point C;

public:
	Triangle();
	~Triangle();

	bool Input();
	bool Read(istream & in);
	bool Write(ostream & out);
	void Print()const;
	const char* GetFigureType();
	void TranslationFigure(Triangle& figure);

	bool CheckPoint(Point point);
	double Area(Point a, Point b, Point c);
	void GetAbsCoordinate();
};
