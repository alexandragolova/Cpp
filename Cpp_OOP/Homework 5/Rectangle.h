#pragma once
#include "Figure.h"
#include "Group.h"

class Rectangle : public Figure, public Group
{
public:
	double Width;
	double Height;

public:
	Rectangle();
	~Rectangle();

	 bool Input();
	 bool Read(istream & in);
	 bool Write(ostream & out);
	 void Print()const;
	 const char* GetFigureType();
	 void TranslationFigure(Rectangle& figure);

	 bool CheckPoint(Point point);
	 void GetAbsCoordinate();

};
