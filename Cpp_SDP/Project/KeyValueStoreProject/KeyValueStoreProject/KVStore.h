#pragma once
#include<string>
#include<iostream>
using namespace std;

class KVStore
{
public:
	KVStore();
	~KVStore();

	string Store(string pBlock);
	bool Load(string pKey, string& pBlock);
	bool Erase(string pKey);

private:
	void RepairStorage();
	bool RemoveInvalidFiles(string file);
	string GetDateTimeNow();
	int CreateNumber(string number);
	string BuildFileName();
};

