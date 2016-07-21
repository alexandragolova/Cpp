#include "PGM.h"
#include<fstream>
#include<iostream>
#include<string>

PGM::PGM() :Image()
{
	MaxGray = 0;
}

PGM::~PGM()
{
	MaxGray = 0;
}

int* PGM::GetBinaryContent()const
{
	int size = GetSize().Height*GetSize().Width;
	int* content = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		content[i] = BinaryContent[i];
	}
	return content;
}

void PGM::SetBinaryContent(int* content)
{
	int size = GetSize().Height*GetSize().Width;
	BinaryContent = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		BinaryContent[i] = content[i];

	}
}

int PGM::GetMaxGray()
{
	return MaxGray;
}

int** PGM::GetContent()const
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

void PGM::SetContent(int** content)
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

void PGM::SetMaxGray(int maxGray)
{
	MaxGray = maxGray;
}

void PGM::ReadASCII(string fileName)
{
	string line;
	string name;
	string format;
	ImageSize size;
	int maxGray;

	char c = '#';

	SetName(fileName);

	ifstream file;
	file.open(GetName().c_str());

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;
	cout << format;
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
	file >> maxGray;
	SetMaxGray(maxGray);

	int** content = new int*[size.Height];
	for (int i = 0; i < size.Height; i++)
	{
		content[i] = new int[size.Width];
	}

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file >> content[height][width];
		}
	}

	SetContent(content);

	return;

}

void PGM::WriteASCII()
{
	ofstream file;

	file.open(GetName().c_str());

	if (!file)
	{
		cout << "  Cannot open file!";
	}
	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	file << GetFormatName() << endl;
	file << "# " << GetName() << endl;
	file << size.Width << "  " << size.Height << endl;
	file << GetMaxGray() << endl;

	int** content = GetContent();

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file << content[height][width]<<" ";
		}
		file << endl;
	}
}

void PGM::ReadBinary(string fileName)
{
	string line;
	string name;
	string format;
	ImageSize size;
	int maxGray;
	int* binaryArray;
	char c = '#';

	ifstream in;
	in.open(fileName.c_str());

	if (!in)
	{
		cout << "  Cannot open  file";
	}
	SetName(fileName);

	ifstream file;
	file.open(GetName().c_str());

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;
	cout << format;
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
	cout << "size:" << size.Width << " " << size.Height;

	SetSize(size);
	file >> maxGray;
	cout << "max:" << maxGray;
	SetMaxGray(maxGray);

	int cnt = size.Width * size.Height * sizeof (int);

	binaryArray = new int[cnt];

	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			in >> *binaryArray;
			if (in.eof())
			{
				return;
			}
			binaryArray++;
		}
	}
	SetBinaryContent(binaryArray);
}

void PGM::WriteBinary()
{
	ofstream file;
	file.open(GetName().c_str(), ios::binary);

	if (!file)
	{
		cout << "Cannot open file ";
	}

	ImageSize size;
	size.Height = GetSize().Height;
	size.Width = GetSize().Width;

	file << "P5" << endl;
	file << "# " << GetName().c_str() << endl;
	file << size.Width << "  " << size.Height << endl;

	int *indexBinaryArray = GetBinaryContent();

	int cnt = 0;
	for (int height = 0; height < size.Height; height++)
	{
		for (int width = 0; width < size.Width; width++)
		{
			file << *indexBinaryArray << " ";
			cnt++;
			indexBinaryArray++;

			if ( width == size.Width - 1 || cnt == size.Width * size.Height)
			{
				file << endl;
			}
			else
			{
				file << " ";
			}
		}
	}
}
