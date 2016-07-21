#pragma once
#include <fstream>
#include"Figure.h"

class FigureProcessing
{

	private:
		ifstream File;

	public:
		FigureProcessing();
		FigureProcessing(const char * Path);
		~FigureProcessing();

		bool OpenFile(const char * Path);
		void CloseFile();
		void Back();
		bool CheckState() const;
		Figure* GetNextFigure();
		Figure* CreateFigure(const char* FigureType);
};

