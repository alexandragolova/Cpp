#include <iostream>
#include "Figure.h"
#include "Triangle.h"

Triangle::Triangle()
{
	A.x = 0;
	A.y = 0;
	B.x = 0;
	B.y = 0;
	C.x = 0;
	C.y = 0;
}

Triangle::~Triangle()
{
	A.x =0;
	A.y = 0;
	B.x = 0;
	B.y = 0;
	C.x = 0;
	C.y = 0;
}

bool Triangle::Input()
{
	cout << "A(x,y): "<<endl;
	cout << "x= ";
	cin >> A.x;
	cout << "y= ";
	cin >> A.y;

	cout << "B(x,y): " << endl;
	cout << "x= ";
	cin >> B.x;
	cout << "y= ";
	cin >> B.y;

	cout << "C(x,y): " << endl;
	cout << "x= ";
	cin >> C.x;
	cout << "y= ";
	cin >> C.y;

	return cin.good();
}

bool Triangle::Read(istream & in)
{
	char buffer[100];

	in >> buffer;

	cout << buffer << " ";

	if (in.fail() || strcmp(this->GetFigureType(), buffer) != 0)
	{
		return false;
	}

	in >> A.x >> A.y;
	in >> A.x >> A.y;
	in >> A.x >> A.y;

	in >> B.x >> B.y;
	in >> B.x >> B.y;
	in >> B.x >> B.y;

	in >> C.x >> C.y;
	in >> C.x >> C.y;
	in >> C.x >> C.y;

	cout << A.x << ' ' << A.y << endl;
	cout << B.x << ' ' << B.y << endl;
	cout << C.x << ' ' << C.y << endl;

	return in.good();
}

bool Triangle::Write(ostream & out)
{
	out << this->GetFigureType() << ' '
		<<A.x << ' '
		<< A.y ;
	out  << ' '
		<< B.x << ' '
		<< B.y ;
	out << ' '
		<< C.x << ' '
		<< C.y ;


	return out.good();
}

void Triangle::Print()const
{

	cout << "    Rectangle ";
	cout << "    A(x,y) =(" << A.x <<","<<A.y<<")"<< endl;
	cout << "    B(x,y) =(" << B.x << "," << B.y << ")" << endl;
	cout << "    C(x,y) =(" << C.x << "," << C.y << ")" << endl;
	cout << endl;
}

const char* Triangle::GetFigureType()
{
	return  FigureTypeToString(FigureType::TriangleFigure);
}

void Triangle::TranslationFigure(Triangle& figure)
{
	A.x += VectorCoortinates.x;
	A.y += VectorCoortinates.y;

	B.x += VectorCoortinates.x;
	B.y += VectorCoortinates.y;

	C.x += VectorCoortinates.x;
	C.y += VectorCoortinates.y;
}

double Triangle::Area(Point a, Point b, Point c)
{
	return abs((a.x*(b.y -b.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2.0);
}

bool Triangle::CheckPoint(Point point)
{
	float ABC = Area(A, B, C);

	float PBC = Area(point, B, C);

	float PAC = Area(A, point, C);

	float PAB = Area(A, B, point);

	return (ABC == PBC + PAC + PAB);
}

void Triangle::GetAbsCoordinate()
{
	cout << "Abs(A,B,C)"<<endl;
	cout << "A(x,y)=(" << abs(A.x) << ", " << abs(A.y) << ")" << endl;
	cout << "A(x,y)=(" << abs(B.x) << ", " << abs(B.y) << ")" << endl;
	cout << "A(x,y)=(" << abs(C.x) << ", " << abs(C.y) << ")" << endl;
}