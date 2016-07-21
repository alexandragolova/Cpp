#pragma once
#include "Figure.h"


struct TranstationVector
{
	int x;
	int y;
};

class Group
{
public:
	int CntFigures=0;
	Figure* Figures;
	TranstationVector VectorCoortinates;
public:
	Group();
	~Group();

	virtual void TranslationFigure(Figure& figure);
};

