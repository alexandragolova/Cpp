#include"Maze.h"
#include<iostream>
using namespace std;

Maze::Maze()
{
	AllocDestinations();
	cntDestinations = 0;
	maze = NULL;
}

Maze::~Maze()
{
	for (size_t i = 0; i < mazeSize.height; i++)
	{
		delete[] maze[i];
	}
	
}

Size Maze::GetMazeSize() {
	return mazeSize;
}

void Maze::SetMazeSize(Size size)
{
	mazeSize = size;
}

Point Maze::GetPoint()
{
	return current;
}

char** Maze::GetMaze() {
	Size size;
	size.height = GetMazeSize().height;
	size.width = GetMazeSize().width;
	char** content = new char*[size.height];
	for (int i = 0; i < size.height; i++)
		content[i] = new char[size.width];

	for (int i = 0; i < size.height; i++)
		for (int j = 0; j < size.width; j++)
			content[i][j] = maze[i][j];

	return content;
}

void Maze::SetMaze(char** newMaze)
{
	Size size;
	size.height = GetMazeSize().height;
	size.width = GetMazeSize().width;

	maze = new char*[size.height];
	for (int i = 0; i < size.height; i++)
		maze[i] = new char[size.width];

	for (int i = 0; i < size.height; i++)
		for (int j = 0; j < size.width; j++)
			maze[i][j] = newMaze[i][j];
}

int Maze::GetCntDestinations() {
	return cntDestinations;
}

void Maze::FindAllPaths(int x, int y, Route *route) {
	if (x < 0 || y < 0 || x >= mazeSize.width || y >= mazeSize.height || maze[x][y] == '#' || maze[x][y] == 1)
		return;

	maze[x][y] = 1;
	Point p;
	p.x = x;
	p.y = y;
	route->AddPointToRoute(p);

	//Search point in destinations
	Destination* destination = 0;

	for (int i = 0; i < cntDestinations; i++)
	{
		Destination* tempDest = Destinations[i];
		Point point = tempDest->GetEndPoint();
		if (point.x == p.x && point.y == p.y)
		{
			destination = Destinations[i];
			break;
		}
	}

	if (destination == 0)
	{
		destination = new Destination();
		destination->SetEndPoint(p);
		Destinations[cntDestinations] = destination;
		cntDestinations++;
	}

	//Clone route
	Route* newRoute = new Route();
	int numPoints = route->GetCntPoints();
	Point* oldRoutePoints =route->GetPoints();

	for (int i = 0; i < numPoints; i++)
		newRoute->AddPointToRoute(oldRoutePoints[i]);
	destination->AddRoute(*newRoute);

	FindAllPaths(x, y + 1, route);
	FindAllPaths(x + 1, y, route);
	FindAllPaths(x, y - 1, route);
	FindAllPaths(x - 1, y, route);

	if (route->GetCntPoints() > 0)
		route->DeletePoint();

	maze[x][y] = 0;
}

void Maze::PrintAllDestinations(int x, int y) {

	Route route = Route();
	FindAllPaths(x, y, &route);

	cout << "Destinations:" << endl;
	for (int i = 0; i < cntDestinations; i++)
	{
		if (Destinations[i]->GetEndPoint().x == x && Destinations[i]->GetEndPoint().y == y)
			continue;

		Point destEndPoint = Destinations[i]->GetEndPoint();
		cout << '(' << destEndPoint.x << "," << destEndPoint.y << ") ";
	}

	cout << endl << "Routes:" << endl;
	for (int i = 0; i < cntDestinations; i++)
	{
		if (Destinations[i]->GetEndPoint().x == x && Destinations[i]->GetEndPoint().y == y)
			continue;

		Destination* destination = Destinations[i];
		int cntRoutes = destination->GetCntRoutes();
		Route* routes = new Route[cntRoutes];
		destination->SortRoutes();
		routes = destination->GetRoutes();

		Point destEndPoint = destination->GetEndPoint();
		cout << '(' << destEndPoint.x << "," << destEndPoint.y << ") " << endl;

		for (int j = 0; j < cntRoutes; j++)
		{
			Route route = routes[j];
			Point* points = route.GetPoints();
			int cntPoints = route.GetCntPoints();

			for (int k = 0; k < cntPoints; k++)
			{
				Point point = points[k];
				cout << '(' << point.x << "," << point.y << ") ";//<<endl;
			}
			cout << endl;
		}
	}
}

void Maze::AllocDestinations()
{
	int cnt = 0;
	for (int i = 0; i < mazeSize.height; i++)
		for (int j = 0; j < mazeSize.width; j++)
			if (maze[i][j] == '.')
				cnt++;

	Destinations = new Destination*[cnt];
}