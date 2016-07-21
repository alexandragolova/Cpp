#include "PBM.h"
#include<fstream>
#include<iostream>
#include<string>

PBM::PBM() :Image()
{
}

PBM::~PBM()
{
}

int** PBM::GetContent()const
{
	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;
	int** content = new int*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		content[i] = new int[size.Width];
	}

	for (int i = 0; i < size.Height; i++)
	{
		for (int j = 0; j < size.Width; j++)
		{
			content[i][j] = Content[i][j];
		}
	}


	return content;
}

void PBM::SetContent(int** content)
{
	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	Content = new int*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		Content[i] = new int[size.Width];
	}

	for (int i = 0; i < size.Height; i++)
	{
		for (int j = 0; j < size.Width; j++)
		{
			Content[i][j] = content[i][j];
		}
	}
}

int* PBM::GetBinaryContent()const
{
	int size = GetSize().Height*GetSize().Width;
	int* content = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		content[i] = BinaryContent[i];
	}
	return content;
}

void PBM::SetBinaryContent(int* content)
{
	int size = GetSize().Height*GetSize().Width;
	BinaryContent = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		BinaryContent[i] = content[i];

	}
}

void PBM::ReadASCII(string fileName)
{
	string line;
	string name;
	string format;
	ImageSize size;

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
	int pixel;
	int** content = new int*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		content[i] = new int[size.Width];
	}
	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file >> pixel;
			content[height][width] = pixel;
		}
	}

	SetContent(content);
	return;

}

void PBM::WriteASCII()
{
	ofstream file;

	file.open(GetName().c_str());

	if (!file)
	{
		cout << "  Cannot open file!";
	}
	int imgHeight = GetSize().Height;
	int imgWidth = GetSize().Width;

	file << GetFormatName() << endl;
	file << "# " << GetName() << endl;
	file << GetSize().Width << "  " << imgHeight << endl;

	int** content = GetContent();

	for (int height = 0; height < imgHeight; height++)
	{
		for (int width = 0; width < imgWidth; width++)
		{
			file << content[height][width] << " ";
		}
		file << endl;
	}

}

void PBM::ReadBinary(string fileName)
{
	int bit;
	char c;
	unsigned char c2;
	int k;
	string format, line;
	ImageSize size;
	int cntBytes = 0;

	ifstream file;
	file.open(fileName.c_str(), ios::binary);

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;
	SetFormat(format);
	char comment = '#';

	getline(file, line);
	while (comment == '#')
	{
		file >> comment;
		if (comment == '#')
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
	int *indexBinary = new int[size.Width * size.Height];


	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			if (width % 8 == 0)
			{
				file.read(&c, 1);
				c2 = (unsigned char)c;
				if (file.eof())
				{
					cout << "  Cannot reading !";
					return;
				}
				cntBytes++;
			}

			k = 7 - width % 8;
			bit = (c2 >> k) % 2;

			*indexBinary = bit;
			indexBinary++;
		}
	}
	SetBinaryContent(indexBinary);
}

void PBM::WriteBinary()
{
	int bit;
	char c = 0;
	int *indexBinary = BinaryContent;
	int k;
	ImageSize size;

	ofstream file;
	file.open(GetName().c_str(), ios::binary);

	if (!file)
	{
		cout << "  Cannot open to writing";
	}

	file << GetFormatName() << endl
		<< GetSize().Width << " "
		<< GetSize().Height << endl;

	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			k = 7 - width % 8;
			bit = (*indexBinary) % 2;
			c = c | (bit << k);

			indexBinary = indexBinary + 1;

			if ((width + 1) % 8 == 0 || width == (size.Width - 1))
			{
				file << c;
				c = 0;
			}
		}
	}
}
