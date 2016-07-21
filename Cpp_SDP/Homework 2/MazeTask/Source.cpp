#include<iostream>
#include<stack>
#include"Destination.h"
#include"Maze.h"
#include"Route.h"
using namespace std;

int main()
{
	Maze* maze = new Maze();
	Size sizeMaze;

	//Input size
	cout << "Input height: ";
	cin >> sizeMaze.height;
	cout << "Input width: ";
	cin >> sizeMaze.width;
	maze->SetMazeSize(sizeMaze);
	
	char ** matrix = new char*[sizeMaze.height];
	Point startPoint;

	//Input matrix
	cout << "Input matrix elements: " << endl;
	for (int i = 0; i < sizeMaze.height; i++)
	{
		matrix[i] = new char[sizeMaze.width];
			cin >> matrix[i];
	}

	//Start point
	do
	{
		cout << "Input start point: "<<endl;
		cin >> startPoint.x >> startPoint.y;

		if (matrix[startPoint.x][startPoint.y] != '.')
		{
			cout << "Incorrect! ";
		}

	} while (matrix[startPoint.x][startPoint.y] != '.');

	/*matrix[0] = "###";
	matrix[1] = "#..";
	matrix[2] = "#..";*/

	maze->SetMaze(matrix);
	maze->PrintAllDestinations(startPoint.x,startPoint.y);
	return 0;
}