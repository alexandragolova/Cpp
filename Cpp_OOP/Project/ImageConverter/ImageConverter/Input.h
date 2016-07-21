#pragma once
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Input
{

private:
	istringstream allCommands;
	vector<string> Strings;
	vector<string> Operations;
	vector<string> FileNames;

public:
	Input();
	~Input();

	void InputString();
	void SplitString();

	vector<string> GetOprations();
	vector<string> GetFileNames();
	string CheckFormat(string fileName);
	void AddOprationToFile(string imageName);
};