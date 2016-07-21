#include "Figure.h"

Figure::Figure()
{

}

Figure:: ~Figure()
{
}

void Figure::Print() const
{

}

FigureType Figure::StringToFigureType(const char* type)
{

	if (strcmp(type, "CircleFigure"))
		return FigureType::CircleFigure;
	else if (strcmp(type, "TriangleFigure"))
		return TriangleFigure;
	else if(strcmp(type, "RectangleFigure"))
		return RectangleFigure;
	else if(strcmp(type, "Group"))
		return GroupType;
	else if(strcmp(type, "OtherFigure"))
		return OtherFigure;
}

const char* Figure::FigureTypeToString(FigureType type){
	switch (type){
	case CircleFigure:
		return "CircleFigure";
	case TriangleFigure:
		return "TriangleFigure";
	case RectangleFigure:
		return "RectangleFigure";
	case GroupType:
		return "Group";
	case OtherFigure:
		return "OtherFigure";
	default:
		return "INVALID ENUM";
	}
}

bool Figure::CheckPoint(Point point)
{
	return false;
}

void Figure::GetAbsCoordinate()
{

}