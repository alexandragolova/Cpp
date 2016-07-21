#include"KVStore.h"
#include<fstream>
#include<iostream>
#include<string>
#include <windows.h>
#include <sstream>
using namespace std;

KVStore::KVStore()
{
	RepairStorage();
}

KVStore::~KVStore()
{
}

///
///This function clear all invalid files from list 
///(file: "_system\\temp_files.txt")
///
void KVStore::RepairStorage()
{
	//List with temp files 
	string dir = "_system\\temp_file.txt";
	string filename;
	ifstream fileGet;
	fileGet.open(dir.c_str(), std::fstream::in);
	fileGet >> filename;
	fileGet.close();

	//Clean file
	ofstream fileClear;
	fileClear.open(dir.c_str(), std::fstream::trunc);
	fileClear.close();

	string path = filename;
	RemoveInvalidFiles(path.c_str());
}

///
///Delete file by key(name)
///
bool KVStore::RemoveInvalidFiles(string file)
{
	return remove(file.c_str()) != 0 ? false : true;
}

///
///This function create file with unique name ->key
///Information in file is param pBlock
///
string KVStore::Store(string pBlock)
{
	//Add file name in list
	string dir = "_system\\temp_file.txt";
	string filename;
	string bName;

	bName = BuildFileName();
	filename = "storage\\" + bName+".txt";
	fstream fileGet;
	fileGet.open(dir.c_str());
	if (!fileGet)
		cout << "Cannot open file!";

	fileGet << filename;
	fileGet.close();

	ofstream newFile;
	newFile.open(filename.c_str());
	if (!newFile)
		cout << "Cannot open file!";

	//Input all infomation in file
	for (size_t i = 0; i < pBlock.length(); i++)
		newFile << pBlock[i];
	newFile.close();

	//Clear file (file state: finished!)
	ofstream fileClear;
	fileClear.open(dir.c_str(), std::fstream::trunc);
	fileClear.close();

	return bName;
}

///
///This function load saved information.
///We need key to see information
///
bool KVStore::Load(string pKey, string& pBlock)
{
	ifstream file;
	string filename;
	filename = "storage\\";
	filename += pKey;
	filename += ".txt";
	file.open(filename.c_str());

	if (!file.good())
		return false;

	file >> pBlock;
	return true;
}

///
///Delete file (by key). 
///First build name "dir"+"key"+"file format"
///
bool KVStore::Erase(string pKey)
{
	string filename;
	filename = "storage\\"+ pKey+ ".txt";

	return remove(filename.c_str()) != 0 ? false : true;
}

string KVStore::GetDateTimeNow()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	std::ostringstream ossMessage;
	ossMessage << st.wYear << st.wMonth << st.wDay << st.wHour << st.wMinute << st.wSecond << st.wMilliseconds;

	string time;
	time = ossMessage.str();

	return time;
}

int KVStore::CreateNumber(string number)
{
	int result = 0;
	for (size_t i = 0; i < number.length(); i++)
	{
		result += (pow(10, number.length() - i - 1) * ((int)number[i] - '0'));
	}
	return result;
}

///
///This function create unique name in store 
///"kvs_element_" + "date"+"counter"
///
string KVStore::BuildFileName()
{
	//Current date string 
	string date;
	date = GetDateTimeNow();
	string counter;

	//Read counter info 
	string filename = "_system\\counter.txt";
	ifstream fileGet;
	fileGet.open(filename.c_str(), std::fstream::in);
	fileGet >> counter;
	fileGet.close();

	//Change counter(prepare for next element)
	int cnt = CreateNumber(counter) + 1;
	ofstream fileClear;
	fileClear.open(filename.c_str(), std::fstream::trunc);
	fileClear << cnt;
	fileClear.close();

	string name = "kvs_element_"+date+ "_" + counter;

	return name;
}