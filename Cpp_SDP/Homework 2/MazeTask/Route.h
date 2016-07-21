#pragma once

struct Point
{
	int x;
	int y;
};

class Route
{
public:
	Route();
	~Route();
	Route& operator=(const Route& right);
	Route(const Route& route);

	Point* GetPoints();
	void AddPointToRoute(const Point& point);
	void DeletePoint();
	int GetCntPoints();

private:
	void Resize(int newSize);
	Point* points;
	int cntPoints;
	int capacity;
};

