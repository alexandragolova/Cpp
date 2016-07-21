#include "Figure.h"
#include "FigureProcessing.h"
#include<vector>

void ReadFigures(vector<Figure*> figureList, const char* Filename)
{
	FigureProcessing figureReader;

	if (!figureReader.OpenFile(Filename))
	{
		cout << Filename<<" cannot open!";
		return;
	}

	Figure *nextFigure = NULL;

	while (nextFigure = figureReader.GetNextFigure())
	{
		figureList.push_back(nextFigure);
	}
}
