#include<iostream>
#include"PBM.h"
#include"PPM.h"
#include"PGM.h"
#include"Input.h"
#include"ImageProcessing.h"
using namespace std;


int main()
{

	Input input;
	input.InputString();
	input.SplitString();

	vector<string> fileNames = input.GetFileNames();
	int cntFile = input.GetFileNames().size();

	for (int i = 0; i < cntFile; i++)
	{
		input.AddOprationToFile(fileNames[i]);
	}

	return 0;
}