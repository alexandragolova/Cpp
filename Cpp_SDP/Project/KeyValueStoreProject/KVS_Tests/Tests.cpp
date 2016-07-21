#include<fstream>
#include<string>
#include"Tests.h"
#include"../KeyValueStoreProject/KVStore.h"
using namespace std;

void Test_KVS()
{
	cout << "Create KVS: ";

	KVStore store = KVStore();

	cout << "OK\n";
}

void Test_KVS_Array()
{
	cout << "Create and delete KVS array: ";

	KVStore* p = new KVStore[10];
	delete[] p;

	cout << "OK\n";
}

void Test_Store()
{
	cout << "Add element to store: ";
	bool IsLoad = true;
	KVStore store = KVStore();
	string key;
	string pBlock;

	key = store.Store("test_content");
	IsLoad = store.Load(key, pBlock) == true ? true : false;

	cout << (IsLoad == true ? "OK\n" : "Failed\n");
}

void Test_Store_Content()
{
	cout << "Add element to store: ";
	bool IsLoad = true;
	KVStore store = KVStore();
	string key;
	string pBlock;
	string test = "test_content";

	key = store.Store(test);
	IsLoad = store.Load(key, pBlock) == true ? true : false;

	cout << (IsLoad == true && pBlock.compare(test) == 0 ? "OK\n" : "Failed\n");
}

void Test_Load()
{
	//Load invlid file
	cout << "Test for invalid name: ";

	KVStore store = KVStore();
	string key = "random_name";
	string pBlock;

	cout << (store.Load(key, pBlock) == false ? "OK\n" : "Failed\n");
}

void Test_Erase()
{
	cout << "Delete element from store: ";

	bool IsErase = true;
	KVStore store = KVStore();
	string key = store.Store("test_content");
	IsErase = store.Erase(key) == true ? true : false;

	cout << (IsErase == true ? "OK\n" : "Failed\n");
}

void Test_RepairStorage()
{
	cout << "Repair storage test: ";

	bool IsRepair = true;

	string dir = "_system\\temp_file.txt";
	string testFile = "storage\\_test.txt";
	string result;

	fstream fileIn;
	fileIn.open(dir.c_str());
	if (!fileIn)
		cout << "Cannot open file!";
	fileIn << testFile;
	fileIn.close();

	KVStore store;

	fstream fileOut;
	fileOut.open(dir.c_str());
	fileOut >> result;
	fileOut.close();
	IsRepair = result.length() == 0 ? true : false;

	cout << (IsRepair == true ? "OK\n" : "Failed\n");
}
