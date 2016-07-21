#pragma once
#include <istream>
#include <ostream>
#include <iostream>

using namespace std;

struct Point
{
	int x;
	int y;
};

enum FigureType
{
	CircleFigure = 0,
	TriangleFigure = 1,
	RectangleFigure = 2,
	GroupType = 3,
	OtherFigure = 4,
};

class Figure
{
public:
	virtual bool Input() = 0;

	virtual bool Read(istream & in) = 0;

	virtual bool Write(ostream & out) = 0;

	virtual void Print() const;

	Figure();

	virtual ~Figure();

	static const char * GetFigureType();

	static const char* FigureTypeToString(FigureType type);

	static FigureType StringToFigureType(const char* type);

	virtual bool CheckPoint(Point point);

	virtual void GetAbsCoordinate();
};