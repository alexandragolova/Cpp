#pragma once
#include "Image.h"

struct RGB
{
	unsigned char* r;
	unsigned char* g;
	unsigned char* b;
};

struct Pixel
{
	int r;
	int g;
	int b;
};

class PPM :	public Image
{
private:
	int MaxRGB;
	Pixel** Content;
	RGB BinaryContent;
public:
	PPM();
	~PPM();

	int GetMaxRGB();
	void SetMaxRGB(int maxGray);

	RGB GetBinaryContent()const;
	void SetBinaryContent(RGB rgb);

	Pixel** GetContent()const;
	void SetContent(Pixel** pixel);

	void ReadBinary(string fileName);
	void ReadASCII(string fileName);

	void WriteBinary();
	void WriteASCII();
};

