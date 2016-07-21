#include<iostream>
#include<vector>
#include <algorithm> 
#include"Figure.h"
#include"Triangle.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Functions.h"

using namespace std;

int main()
{
	Point point;

	cout << "Input point:"<<endl;
	cout <<"x=";
	cin >> point.x;
	cout << "y=";
	cin >> point.y;

	vector<Figure*> figureList;
	char Filename[260];

	cout << "Enter a file to read from: ";
	cin.get(Filename, 260);

	ReadFigures(figureList, Filename);

	for (vector<Figure*>::iterator it = figureList.begin(); it != figureList.end(); ++it) {
		(*it)->CheckPoint(point);
	}
	
	return 0;
}