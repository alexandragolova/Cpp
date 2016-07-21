#include"Route.h"
Route::Route()
{
	cntPoints = 0;
	capacity = 10;
	points = new Point[capacity];
}

Route::~Route()
{
	delete[] points;
}

Route& Route::operator=(const Route& right)
{
	if (this == &right)
		return *this;

	this->cntPoints = right.cntPoints;
	this->capacity = right.capacity;
	this->points = new Point[cntPoints];

	for (int i = 0; i < cntPoints; i++)
	{
		this->points[i] = right.points[i];
	}

	return *this;
}

Route::Route(const Route& route)
{
	cntPoints = route.cntPoints;
	capacity = route.capacity;
	points = new Point[capacity];

	for (int i = 0; i < cntPoints; i++)
	{
		this->points[i] = route.points[i];
	}
}

Point* Route::GetPoints()
{
	return points;
}

void Route::AddPointToRoute(const Point& point)
{
	if (cntPoints == capacity)
	{
		Resize(capacity * 2);
	}
	
	points[cntPoints].x = point.x;
	points[cntPoints].y = point.y;
	cntPoints++;
}

int Route::GetCntPoints()
{
	return cntPoints;
}

void Route::Resize(int newCapacity)
{
	Point* temp = new Point[newCapacity];
	for (int i = 0; i < cntPoints; i++)
		temp[i] = points[i];

	capacity = newCapacity;
	delete[] points;
	points = temp;
}

void Route::DeletePoint()
{
	if (cntPoints < 0)
		return;

	--cntPoints;

	//todo: resize me
}