#include <iostream>
#include "Figure.h"
#include "Rectangle.h"

Rectangle::Rectangle()
{
	Width = 0;
	Height = 0;
}

Rectangle::~Rectangle()
{
	Width = 0;
	Height = 0;
}

bool Rectangle::Input()
{
	cout << "Width= ";
	cin >> Width;

	cout << "Height= ";
	cin >> Height;

	return cin.good();
}

bool Rectangle::Read(istream & in)
{
	char buffer[100];

	in >> buffer;

	cout << buffer << " ";

	if (in.fail() || strcmp(this->GetFigureType(), buffer) != 0)
	{
		return false;
	}

	in >> Width >> Height;

	cout << Width << ' ' << Height << endl;

	return in.good();
}

bool Rectangle::Write(ostream & out)
{
	out << this->GetFigureType() << ' '
		<< Width << ' '
		<< Height << endl;

	return out.good();
}

void Rectangle::Print()const
{
	cout << "    Rectangle ";
	cout << "    Width: " << Width << endl;
	cout << "    Height: " << Height << endl;
	cout << endl;
}

const char* Rectangle::GetFigureType()
{
	return  FigureTypeToString(FigureType::RectangleFigure);
}

void Rectangle::TranslationFigure(Rectangle& figure)
{ 
	Width += VectorCoortinates.x;
	Height += VectorCoortinates.y;
}

bool Rectangle::CheckPoint(Point point)
{
	if (point.x <= Width && point.y <= Height)
		return true;
	else return false;
}

void Rectangle::GetAbsCoordinate()
{
	cout << "Abs(Width,Height)" << endl;
	cout << "Width=" << abs(Width) << ", Height=" << abs(Height) <<endl;
}