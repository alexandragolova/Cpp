#include<iostream>
#include<string>
#include"Stack.h"
using namespace std;

int main()
{
	Stack<string> stack = Stack<string>(3);

	stack.push("first");
	stack.push("second");

	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
	return 0;
}