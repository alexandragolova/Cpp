#include <iostream>
#include "Circle.h"
using namespace std;

Circle::Circle()
{
	X = 0;
	Y = 0;
	Radius = 0;
}

Circle::~Circle()
{
	X = 0;
	Y = 0;
	Radius = 0;
}

bool Circle::Input()
{
	cout << "X= ";
	cin >> X;

	cout << "Y= ";
	cin >> Y;

	cout << "R= ";
	cin >> Radius;

	return cin.good();
}

bool Circle::Read(istream & in)
{
	char buffer[100];

	in >> buffer;

	cout << buffer << " ";

	const char* type = this->GetFigureType();

	if (in.fail() || strcmp(type, buffer) != 0)
	{
		return false;
	}

	in >> X >> Y >> Radius;

	cout << X << ' ' << Y << ' ' << Radius << endl;

	return in.good();
}

bool Circle::Write(ostream & out)
{
	out << this->GetFigureType() << ' '
		<< X << ' '
		<< Y << ' '
		<< Radius << endl;

	return out.good();
}

void Circle::Print()const
{
	cout << "    Circle:";
	cout << "    X: " << X << endl;
	cout << "    Y: " << Y << endl;
	cout << "    Radius: " << Radius << endl;
	cout << endl;
}

const char* Circle::GetFigureType()
{
	return  FigureTypeToString(FigureType::CircleFigure);
}

void Circle::TranslationFigure(Circle& figure)
{
	X += VectorCoortinates.x;
	Y += VectorCoortinates.y;
}

bool Circle::CheckPoint(Point point)
{
	if (point.x <= X && point.y <= Y)
		return true;
	else return false;
}

void Circle::GetAbsCoordinate()
{
	cout << "Abs(R,X,Y)" << endl;
	cout << "R=" << abs(Radius) << ", X=" << abs(X) << ", Y=" << abs(Y) << endl;
}