#include "FigureProcessing.h"
#include"Figure.h"
#include"Triangle.h"
#include"Rectangle.h"
#include"Circle.h"

FigureProcessing::FigureProcessing()
{

}

FigureProcessing::~FigureProcessing()
{

}

bool FigureProcessing::OpenFile(const char * Path)
{
	File.open(Path);

	return File.good();
}

void FigureProcessing::CloseFile()
{
	File.close();
}

bool FigureProcessing::CheckState() const
{
	return File.good();
}

void FigureProcessing::Back()
{
	if (CheckState())
	{
		File.seekg(0, ios::beg);
	}
}

Figure* FigureProcessing::CreateFigure(const char* Type)
{
	FigureType type = Figure::StringToFigureType(Type);
	switch (type)
	{
	case CircleFigure:return new Circle();

	case RectangleFigure:return new Rectangle();

	case TriangleFigure:return new Triangle();

	default:
		break;
	}

}

Figure* FigureProcessing::GetNextFigure()
{
	int pos = File.tellg();

	char temp[100];

	File >> temp;

	File.seekg(pos, ios::beg);

	Figure * pFigure = FigureProcessing::CreateFigure(temp);

	if (pFigure)
	{
		pFigure->Read(File);
	}

	return pFigure;
}