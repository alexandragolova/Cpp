#pragma once
#include<iostream>
using namespace std;
struct ImageSize
{
	int Width;
	int Height;
};

class Image
{
private:
	string Name;
	string Format;
	string Path;
	ImageSize Size;

public:
	Image();
	Image(const Image& image);
	Image& operator =(const Image& image);
	virtual ~Image();

	string GetName()const;
	string GetPath()const ;
	ImageSize GetSize()const ;
	string GetFormatName()const;
	int** GetContent()const;

	void SetName(string name);
	void SetPath(string path);
	void SetSize(ImageSize size);
	void SetFormat(string format);
	void SetContent(int** content);
};