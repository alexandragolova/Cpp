#include "Input.h"
#include"Image.h"
#include"ImageProcessing.h"
#include<string>
#include <fstream>
#include<fstream>
#include<iostream>
#include"PBM.h"
using namespace std;

Input::Input()
{
	Strings.resize(0);
	Operations.resize(0);
	FileNames.resize(0);
}

Input::~Input()
{
	Strings.clear();
	Operations.clear();
	FileNames.clear();
}

//Въвеждане на операции и файлове
void Input::InputString()
{
	//string input;
	//cout << "prog.exe>> ";
	//getline(cin, input);
	//allCommands.str(input);
	
	//allCommands.str("ppm.ppm pgm.pgm pbm.pbm --grayscale --monochrome");

	allCommands.str("ppm.ppm --histogram=red");
}

//Разделяне на валидните операции и именатана файлове
void Input::SplitString(){

	string s;
	while (getline(allCommands, s, ' ')) {
		Strings.push_back(s);
	}

	for (int i = 0; i < Strings.size(); ++i)
	{
		if (!Strings[i].find_first_of("--"))
		{
			Operations.push_back(Strings[i]);
		}
		else
		{
			FileNames.push_back(Strings[i]);
		}
	}
}

vector<string> Input::GetOprations(){
	return Operations;
}

vector<string> Input::GetFileNames(){
	return FileNames;
}

string Input::CheckFormat(string fileName)
{
	ifstream file;
	string line;
	string format;

	file.open(fileName);

	if (!file.good())
	{
		cout << "Can not open file";
	}
	file >> format;

	if (format == "P1" || format == "p1")
		return format = "P1";
	if (format == "P2" || format == "p2")
		return format = "P2";
	if (format == "P3" || format == "p3")
		return format = "P3";
	if (format == "P4" || format == "p4")
		return format = "P4";
	if (format == "P5" || format == "p5")
		return format = "P5";
	if (format == "P6" || format == "p6")
		return format = "P6";

	file.close();

}

//Прилагане на подадените от потребителя операции към даден файл (според форната на файла)
void Input::AddOprationToFile(string imageName)
{
	ImageProcessing imgProcessing;
	vector<string> operations = GetOprations();
	int cntOprations = GetOprations().size();
	string format = CheckFormat(imageName);


	for (int i = 0; i < cntOprations; i++)
	{
		if (operations[i] == "--grayscale")
		{
			if (format == "P3")
			{
				PPM* ppmImage = new PPM();
				ppmImage->ReadASCII(imageName);
				ppmImage->SetFormat(format);
				imgProcessing.PPMtoGrayscale(ppmImage);
			}
			if (format == "P2")
			{
				PGM* pgmImage = new PGM();
				pgmImage->ReadASCII(imageName);
				pgmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "grayscale");
				pgmImage->SetName(newName);
				pgmImage->WriteASCII();
			}
			if (format == "P1")
			{
				PBM* pbmImage = new PBM();
				pbmImage->ReadASCII(imageName);
				pbmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "grayscale");
				pbmImage->SetName(newName);
				pbmImage->WriteASCII();

			}

		}

		else if (operations[i] == "--monochrome")
		{
			if (format == "P2")
			{
				PGM* pgmImage = new PGM();
				pgmImage->ReadASCII(imageName);
				pgmImage->SetFormat(format);
				imgProcessing.PGMtoMonochrome(pgmImage);

			}
			else if (format == "P3")
			{
				PPM* ppmImage = new PPM();
				ppmImage->ReadASCII(imageName);
				ppmImage->SetFormat(format);
				imgProcessing.PPMtoMonochrome(ppmImage);
			}
			else
			{
				PBM* pbmImage = new PBM();
				pbmImage->ReadASCII(imageName);
				pbmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "monochrome");
				pbmImage->SetName(newName);
				pbmImage->WriteASCII();
			}
		}
		else if (operations[i] == "--histogram=red")
		{
			if (format == "P3")
			{
				PPM* ppmImage = new PPM();
				ppmImage->ReadASCII(imageName);
				ppmImage->SetFormat(format);
				imgProcessing.Histogram(ppmImage, 'r');
			}
			if (format == "P2")
			{
				PGM* pgmImage = new PGM();
				pgmImage->ReadASCII(imageName);
				pgmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_red");
				pgmImage->SetName(newName);
				pgmImage->WriteASCII();
			}
			if (format == "P1")
			{
				PBM* pbmImage = new PBM();
				pbmImage->ReadASCII(imageName);
				pbmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_red");
				pbmImage->SetName(newName);
				pbmImage->WriteASCII();

			}

		}
		else if (operations[i] == "--histogram=green")
		{
			if (format == "P3")
			{
				PPM* ppmImage = new PPM();
				ppmImage->ReadASCII(imageName);
				ppmImage->SetFormat(format);
				imgProcessing.Histogram(ppmImage, 'g');
			}
			if (format == "P2")
			{
				PGM* pgmImage = new PGM();
				pgmImage->ReadASCII(imageName);
				pgmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_green");
				pgmImage->SetName(newName);
				pgmImage->WriteASCII();
			}
			if (format == "P1")
			{
				PBM* pbmImage = new PBM();
				pbmImage->ReadASCII(imageName);
				pbmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_green");
				pbmImage->SetName(newName);
				pbmImage->WriteASCII();

			}
		}
		else if (operations[i] == "--histogram=blue")
		{
			if (format == "P3")
			{
				PPM* ppmImage = new PPM();
				ppmImage->ReadASCII(imageName);
				ppmImage->SetFormat(format);
				imgProcessing.Histogram(ppmImage, 'b');
			}

			if (format == "P2")
			{
				PGM* pgmImage = new PGM();
				pgmImage->ReadASCII(imageName);
				pgmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_blue");
				pgmImage->SetName(newName);
				pgmImage->WriteASCII();
			}
			if (format == "P1")
			{
				PBM* pbmImage = new PBM();
				pbmImage->ReadASCII(imageName);
				pbmImage->SetFormat(format);
				string newName = imgProcessing.CreateNewName(imageName, "histogram_blue");
				pbmImage->SetName(newName);
				pbmImage->WriteASCII();

			}
		}
	}
}
