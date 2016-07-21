#include"Route.h"
#pragma once

class Destination
{
private:
	void ResizeRoute(int newSize);
	Route* routes;
	int cntRoutes;
	int capacity;
	Point endPoint;

public:
	Destination();
	~Destination();
	Destination& operator=(const Destination& destination);
	Destination(const Destination& dest);

	void SortRoutes();
	Point GetEndPoint();
	void SetEndPoint(Point point);
	
	Route* GetRoutes();
	void AddRoute(const Route& route);

	int GetCntRoutes();
};
