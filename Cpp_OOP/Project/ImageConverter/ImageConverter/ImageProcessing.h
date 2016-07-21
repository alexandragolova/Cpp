#pragma once
#include"PPM.h"
#include"PGM.h"
class ImageProcessing
{
public:
	ImageProcessing();
	~ImageProcessing();

	void PPMtoGrayscale(PPM *ppmImage);
	void PPMtoMonochrome(PPM *ppmImage);
	void PGMtoMonochrome(PGM *pgmImage);
	void Histogram(PPM *ppmImage, char color);
	string CreateNewName(string fileName, string operation);
};

