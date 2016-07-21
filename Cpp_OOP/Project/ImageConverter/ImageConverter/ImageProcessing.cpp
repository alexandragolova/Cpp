#include "ImageProcessing.h"
#include"PPM.h"
#include"PGM.h"
#include"Image.h"
#include<fstream>
#include<iostream>
#include<string>

ImageProcessing::ImageProcessing()
{
}

ImageProcessing:: ~ImageProcessing()
{

}

string ImageProcessing::CreateNewName(string fileName, string operation)
{
	string newName = operation + '_' + fileName;

	return newName;
}

void ImageProcessing::PPMtoGrayscale(PPM *ppmImage)
{
	string name = CreateNewName(ppmImage->GetName(), "grayscale_");
	ofstream file(name);

	if (!file.good())
	{
		cout << "Error opening file";
		return;
	}
	ImageSize size;
	size.Height = ppmImage->GetSize().Height;
	size.Width = ppmImage->GetSize().Width;

	file << ppmImage->GetFormatName() << endl;
	file << size.Width << " " << size.Height << endl;
	file << ppmImage->GetMaxRGB() << endl;

	Pixel** content = ppmImage->GetContent();

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			int pixel = (content[height][width].r + content[height][width].g + content[height][width].b) / 3;
			file << pixel << " " << pixel << " " << pixel << " ";
		}

		file << endl;
	}
	cout << ppmImage->GetName() << " to grayscale " << endl;
}

void ImageProcessing::PPMtoMonochrome(PPM *ppmImage)
{
	string name = CreateNewName(ppmImage->GetName(), "monochrome_");
	ofstream file(name);

	int pixel, current;
	if (file.fail())
	{
		cout << "Error opening file";
		return;
	}
	file << ppmImage->GetFormatName() << endl;
	file << ppmImage->GetSize().Width << " " << ppmImage->GetSize().Height << endl;
	ImageSize size;
	size.Height = ppmImage->GetSize().Height;
	size.Width = ppmImage->GetSize().Width;

	Pixel** content = ppmImage->GetContent();

	int maxRGB = ppmImage->GetMaxRGB();

	for (int i = 0; i < size.Height; i++)
	{
		for (int j = 0; j < size.Width; j++)
		{
			int pixelContent = (content[i][j].r + content[i][j].g + content[i][j].b) / 3;
			if (pixelContent >= (maxRGB / 2))
			{
				pixel = 1;
			}
			else
			{
				pixel = 0;
			}
			file << pixel << " ";
		}
		file << endl;
	}
	cout << ppmImage->GetName() << " to monochrome " << endl;
}

void ImageProcessing::PGMtoMonochrome(PGM *pgmImage)
{
	string name = CreateNewName(pgmImage->GetName(), "monochrome_");
	ofstream file(name);
	int pixel;
	if (file.fail())
	{
		cout << "Error opening file";
		return;
	}

	file << pgmImage->GetFormatName() << endl;
	file << pgmImage->GetSize().Width << " " << pgmImage->GetSize().Width << endl;

	int imgWidth = pgmImage->GetSize().Width;
	int imgHeigth = pgmImage->GetSize().Height;
	int** imgContent = pgmImage->GetContent();
	int imgMaxGray = pgmImage->GetMaxGray();

	for (int i = 0; i < imgHeigth; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			if (imgContent[i][j] >= imgMaxGray / 2)
			{
				pixel = 1;
			}
			else
			{
				pixel = 0;
			}
			file << pixel << " ";
		}
		file << endl;
	}
	cout << pgmImage->GetName() << " to monochrome" << endl;
}

void ImageProcessing::Histogram(PPM *ppmImage, char color)
{
	string name = CreateNewName(ppmImage->GetName(), "histogram_");

	switch (color)
	{
	case 'r':
		name = CreateNewName(ppmImage->GetName(), "histogram_red");
		break;
	case 'g':
		name = CreateNewName(ppmImage->GetName(), "histogram_green");
		break;
	case 'b':
		name = CreateNewName(ppmImage->GetName(), "histogram_blue");
		break;
	default:
		break;
	}

	ofstream file(name);

	file << ppmImage->GetFormatName()
		<< endl
		<< "256 101"
		<< endl
		<< "255\n";

	int* histogram = new int[256];
	for (int i = 0; i < 256; i++)
	{
		histogram[i] = 0;
	}
	int cntPixel = 0;

	int colorCode = 0;
	switch ((int)color)
	{
	case 'r':
	case 'R':
		colorCode = 0;
		cout << ppmImage->GetName() << " red histogram " << endl;
		break;
	case 'G':
	case 'g':
		colorCode = 1;
		cout << ppmImage->GetName() << " green histogram" << endl;
		break;
	case 'B':
	case 'b':
		colorCode = 2;
		cout << ppmImage->GetName() << " blue  histogram " << endl;
		break;
	default:
		break;
	}

	int imgHeight = ppmImage->GetSize().Height;
	int imgWidth = ppmImage->GetSize().Width;
	Pixel** imgContent = ppmImage->GetContent();
	int pixel;

	for (int height = 0; height < imgHeight; height++)
	{
		for (int width = 0; width < imgWidth; width++)
		{
			switch (colorCode)
			{
			case 0:
				pixel = imgContent[height][width].r;
				histogram[pixel]++;
				break;
			case 1:
				pixel = imgContent[height][width].g;
				histogram[pixel]++;
				break;
			case 2:
				pixel = imgContent[height][width].b;
				histogram[pixel]++;
				break;
			default:
				break;
			}
		}
	}

	for (size_t i = 0; i < 256; i++)
	{
		cntPixel += histogram[i];
	}

	for (int width = 0; width < 256; width++)
	{
		histogram[width] = (int)((float)100 * (float)histogram[width] / (float)cntPixel);
	}

	for (int height = 100; height >= 0; height--)
	{
		for (int width = 0; width < 256; width++)
		{
			Pixel rgb;
			rgb.r = 255;
			rgb.g = 255;
			rgb.b = 255;

			switch (colorCode)
			{
			case 0:
				if (histogram[width] >= height)
				{
					rgb.r = 255;
					rgb.g = 0;
					rgb.b = 0;
				}
				break;
			case 1:
				if (histogram[width] >= height)
				{
					rgb.r = 0;
					rgb.g = 255;
					rgb.b = 0;
				}

				break;
			case 2:
				if (histogram[width] >= height)
				{
					rgb.r = 0;
					rgb.g = 0;
					rgb.b = 255;

				}
				break;
			}
			file << rgb.r << " " << rgb.g << " " << rgb.b << " ";
		}
		file << endl;
	}
}
