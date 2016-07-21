#include"KVStore.h"
#include<iostream>
#include<string>
#include<exception>
using namespace std;

struct StoreFile {
	string Content;
};
int main()
{
	KVStore store = KVStore();
	string key;
	StoreFile storeFile;
	string input;
	char operation = input[0];

	do {
		cout << "========================================" << endl;
		cout << "Input operation:" << endl;
		cout << "1.Add element to store" << endl;
		cout << "2.Get element by key" << endl;
		cout << "3.Delete element from store (by key)" << endl;
		cout << "4.Exit" << endl;
		cout << "========================================" << endl;
		cout << "Input opration : ";
		cin >> input;
		operation = input[0];

		if (operation == '1')
		{
			cout << "Input content: ";
			cin >> storeFile.Content;
			cout << store.Store(storeFile.Content) << endl;;
		}
		else if (operation == '2')
		{
			cout << "Input key: ";
			cin >> key;
			if (store.Load(key, storeFile.Content) == 0)
				cout << "Invalid key!" << endl;
			else cout << storeFile.Content << endl;;
		}
		else if (operation == '3')
		{
			cout << "Input key: ";
			cin >> key;
			if (store.Erase(key) == 0)
				cout << "Invalid key!" << endl;
			else cout << "File was successfully deleted!" << endl;
		}
		else if (operation == '4')
			return 0;
		else 
			cout << "Invalid operation! Try again :)" << endl;

	} while (operation != '4');
	return 0;
}