#include"Tests.h"
#include<iostream>
using namespace std;

int main()
{
	Test_KVS();
	Test_KVS_Array();
	Test_Store();
	Test_Store_Content();
	Test_Load();
	Test_Erase();
	Test_RepairStorage();

	return 0;
}