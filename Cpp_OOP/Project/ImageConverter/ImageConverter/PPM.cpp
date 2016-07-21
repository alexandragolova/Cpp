#include "PPM.h"
#include<fstream>
#include<iostream>
#include<string>

PPM::PPM() :Image()
{
	MaxRGB = 0;
}

PPM::~PPM()
{
	MaxRGB = 0;
}

int PPM::GetMaxRGB()
{
	return MaxRGB;
}

void PPM::SetMaxRGB(int maxGray)
{
	MaxRGB = maxGray;
}

RGB  PPM::GetBinaryContent()const
{
	RGB rgb;
	rgb.r = BinaryContent.r;
	rgb.g = BinaryContent.g;
	rgb.b = BinaryContent.b;

	return rgb;
}

void  PPM::SetBinaryContent(RGB rgb)
{
	BinaryContent.r = rgb.r;
	BinaryContent.g = rgb.g;
	BinaryContent.b = rgb.b;
}

Pixel** PPM::GetContent()const
{
	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	Pixel** content = new Pixel*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		content[i] = new Pixel[size.Width];
	}

	for (int i = 0; i < size.Height; i++)
	{
		for (int j = 0; j < size.Width; j++)
		{
			content[i][j].r = Content[i][j].r;
			content[i][j].g = Content[i][j].g;
			content[i][j].b = Content[i][j].b;
		}
	}
	return content;
}

void PPM::SetContent(Pixel** content)
{
	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	Content = new Pixel*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		Content[i] = new Pixel[size.Width];
	}

	for (int i = 0; i < size.Height; i++)
	{
		for (int j = 0; j < size.Width; j++)
		{
			Content[i][j].r = content[i][j].r;
			Content[i][j].g = content[i][j].g;
			Content[i][j].b = content[i][j].b;
		}
	}
}

void PPM::ReadASCII(string fileName)
{
	string line;
	string name;
	string format;
	ImageSize size;
	Pixel rgb;
	int maxRGB, pixel;

	char c = '#';

	SetName(fileName);
	ifstream file;
	file.open(GetName().c_str());

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;
	SetFormat(format);

	getline(file, line);
	while (c == '#')
	{
		file >> c;
		if (c == '#')
		{
			getline(file, line);
			continue;
		}
		else
		{
			int put = file.tellg();
			file.seekg(put - 3);
			break;
		}
	}

	file >> size.Width >> size.Height;
	SetSize(size);
	file >> maxRGB;
	SetMaxRGB(maxRGB);

	Pixel** content = new Pixel*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		content[i] = new Pixel[size.Width];
	}
	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file >> rgb.r >> rgb.g >> rgb.b;
			content[height][width].r = rgb.r;
			content[height][width].g = rgb.g;
			content[height][width].b = rgb.b;
		}
	}
	SetContent(content);

	return;
}

void PPM::WriteASCII()
{
	ofstream file;

	file.open(GetName().c_str());

	if (!file)
	{
		cout << "Cannot open file!";
	}

	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;
	file << GetFormatName() << endl;
	file << "# " << GetName() << endl;
	file << size.Width << "  " << size.Height << endl;
	file << GetMaxRGB() << endl;

	Pixel** content = GetContent();

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file << content[height][width].r << content[height][width].g << content[height][width].b << " ";
		}
		file << endl;
	}

}

void PPM::ReadBinary(string fileName)
{
	bool readingError;
	string line;
	string name;
	string format;
	ImageSize size;
	int maxRGB, pixel;

	char c = '#';

	ifstream input;
	input.open(fileName.c_str(), ios::binary);

	if (!input)
	{
		cout << "  Cannot open file!";
	}
	SetName(fileName);
	cout << GetName();
	ifstream file;
	file.open(GetName().c_str());

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;
	SetFormat(format);
	while (c == '#')
	{
		file >> c;
		if (c == '#')
		{
			getline(file, line);
			continue;
		}
		else
		{
			int put = file.tellg();
			file.seekg(put - 3);
			break;
		}
	}

	file >> size.Width >> size.Height;
	cout << "Width:" << size.Width << " " << "Height:" << size.Height << endl;
	SetSize(size);
	file >> maxRGB;
	SetMaxRGB(maxRGB);


	RGB rgb;
	rgb.r = new unsigned char[size.Width * size.Height];
	rgb.g = new unsigned char[size.Width * size.Height];
	rgb.b = new unsigned char[size.Width * size.Height];

	ImageSize imgSize;

	for (imgSize.Height = 0; imgSize.Height < size.Height; imgSize.Height++)
	{
		for (imgSize.Width = 0; imgSize.Width < size.Width; imgSize.Width++)
		{
			file.read(&c, 1);
			*rgb.r = (unsigned char)c;
			rgb.r = rgb.r + 1;
			readingError = file.eof();
			if (readingError)
			{
				cout << "Reading error: ";
				cout << " Pixel (" << imgSize.Width << ", " << imgSize.Height << ")" << endl;
			}

			file.read(&c, 1);
			*rgb.g = (unsigned char)c;
			rgb.g = rgb.g + 1;
			readingError = file.eof();
			if (readingError)
			{
				cout << "Reading error: ";
				cout << " Pixel (" << imgSize.Width << ", " << imgSize.Height << ")" << endl;

			}

			file.read(&c, 1);
			*rgb.b = (unsigned char)c;
			rgb.b = rgb.b + 1;
			readingError = file.eof();
			if (readingError)
			{
				cout << "Reading error: ";
				cout << " Pixel (" << imgSize.Width << ", " << imgSize.Height << ")" << endl;
			}

		}
	}

}

void PPM::WriteBinary()
{
	ImageSize size;
	RGB indexRGB;
	int maxrgb = 0;
	ofstream file;

	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	file.open(GetName().c_str(), ios::binary);

	if (!file)
	{
		cout << " Writing error!";
	}
	indexRGB.r = BinaryContent.r;
	indexRGB.g = BinaryContent.g;
	indexRGB.b = BinaryContent.b;

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			if (maxrgb <= (int)indexRGB.r)
			{
				maxrgb = (int)indexRGB.r;
			}
			if (maxrgb <= (int)indexRGB.g)
			{
				maxrgb = (int)indexRGB.g;
			}
			if (maxrgb <= (int)indexRGB.b)
			{
				maxrgb = (int)indexRGB.b;
			}

			indexRGB.r = indexRGB.r + 1;
			indexRGB.g = indexRGB.g + 1;
			indexRGB.b = indexRGB.b + 1;
		}
	}

	file << "P6" << " "
		<< size.Width << " "
		<< size.Width << " "
		<< maxrgb << "\n";

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file << indexRGB.r;
			indexRGB.r = indexRGB.r + 1;
			file << indexRGB.g;
			indexRGB.g = indexRGB.g + 1;
			file << indexRGB.b;
			indexRGB.b = indexRGB.b + 1;
		}
	}

	SetBinaryContent(indexRGB);
}


