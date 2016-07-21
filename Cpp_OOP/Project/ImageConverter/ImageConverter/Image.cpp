#include"Image.h"
#include<iostream>
#include<vector>
# include <fstream>
#include<string>

Image::Image()
{
	Path.resize(0);
	Name.resize(0);
	Format.resize(0);
	Size.Height = 0;
	Size.Width = 0;
}

Image::~Image()
{
	Path.clear();
	Name.clear();
	Format.clear();
	Size.Height = 0;
	Size.Width = 0;
}

Image::Image(const Image& image)
{
	Name = image.Name;
	Path = image.Path;
	Format = image.Format;
	Size.Height = image.Size.Height;
	Size.Width = image.Size.Width;
}

Image& Image::operator =(const Image& image)
{
	Name = image.Name;
	Path = image.Path;
	Format = image.Format;
	Size.Height = image.Size.Height;
	Size.Width = image.Size.Width;

	return *this;
}

void Image::SetName(string name)
{
	Name = name;
}

void Image::SetPath(string path)
{
	Path = path;
}

void Image::SetSize(ImageSize size)
{
	Size.Height = size.Height;
	Size.Width = size.Width;
}

void Image::SetFormat(string format)
{
	Format = format;
}

string  Image::GetName()const
{
	return Name;
}

string  Image::GetPath()const
{
	return Path;
}

ImageSize Image::GetSize()const
{
	return Size;
}

string  Image::GetFormatName()const
{
	return Format;
}

