#pragma once
#include"Destination.h"
#include"Route.h"
struct Size
{
	int height;
	int width;
};

class Maze
{
public:
	Maze();
	~Maze();
	void AllocDestinations();

	int GetCntDestinations();

	Size GetMazeSize();
	void SetMazeSize(Size size);

	Point GetPoint();

	char** GetMaze();
	void SetMaze(char** newMaze);

	void FindAllPaths(int x, int y, Route* route);
	void PrintAllDestinations(int x, int y);
private:
	Destination** Destinations;
	int cntDestinations;
	char** maze;
	Size mazeSize;
	Point current;
};