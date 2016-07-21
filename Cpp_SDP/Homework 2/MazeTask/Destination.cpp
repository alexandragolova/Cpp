#include"Destination.h"

Destination::Destination()
{
	cntRoutes = 0;
	capacity = 10;
	routes = new Route[capacity];
}

Destination::~Destination() {
	delete[] routes;
}

Destination::Destination(const Destination& dest)
{
	cntRoutes = dest.cntRoutes;
	capacity = dest.capacity;
	endPoint = dest.endPoint;
	routes = new Route[capacity];

	for (int i = 0; i < cntRoutes; i++)
	{
		this->routes[i] = dest.routes[i];
	}
}

Destination& Destination::operator=(const Destination& destination) 
{
	if (this == &destination)
		return *this;

	this->cntRoutes = destination.cntRoutes;
	this->capacity = destination.capacity;
	this->endPoint = destination.endPoint;
	this->routes = new Route[cntRoutes];

	for (int i = 0; i < cntRoutes; i++)
	{
		this->routes[i] = destination.routes[i];
	}
	return *this;
}

void Destination::SortRoutes()
{
	int i, j;
	int min;

	for (j = 0; j < cntRoutes - 1; j++) {

		min = j;
		for (i = j + 1; i < cntRoutes; i++) {
			if (routes[i].GetCntPoints() < routes[min].GetCntPoints()) {
				min = i;
			}
		}
		if (min != j) {
			Route rt = routes[j];
			routes[j] = routes[min];
			routes[min] = rt;
		}
	}
}

Point Destination::GetEndPoint() {
	return endPoint;
}

void Destination::SetEndPoint(Point point) {
	endPoint.x = point.x;
	endPoint.y = point.y;
}

Route* Destination::GetRoutes() {

	Route* newRoutes = new Route[cntRoutes];
	for (int i = 0; i < cntRoutes; i++)
	{
		newRoutes[i] = routes[i];
	}
	return newRoutes;
}

void Destination::AddRoute(const Route& route) {
	if (cntRoutes == capacity)
	{
		ResizeRoute(capacity * 2);
	}

	routes[cntRoutes] =route;
	cntRoutes++;
}

void Destination::ResizeRoute(int newSize) {

	Route* temp = new Route[newSize];
	for (int i = 0; i < cntRoutes; i++)
		temp[i] = routes[i];

	capacity = newSize;
	delete[] routes;
	routes = temp;
}

int Destination::GetCntRoutes()
{
	return cntRoutes;
}