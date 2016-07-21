#include<iostream>
#include<string>
#include <cstdlib>
#include"Stack.cpp"
using namespace std;

bool IsLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a'&& c <= 'z');
}

bool IsDigit(char c)
{
	return c >= '0' && c <= '9';
}

int TypeOfChar(char c)
{
	if (IsLetter(c))
		return 1;
	if (IsDigit(c))
		return 2;
	if (c == ')')
		return 3;
	if (c == '(')
		return 4;

	return 0;
}

string Print(Stack<string> strStack)
{
	//обръщаме стека
	Stack<string> helperStack = Stack<string>::Stack(strStack.size());
	while (!strStack.empty())
	{
		helperStack.push(strStack.top());
		strStack.pop();
	}
	strStack = helperStack;

	//временен стек в който се съхраняват елементите до първата срещната затваряща
	Stack<string> tempStack = Stack<string>::Stack(strStack.size());
	while (!strStack.empty())
	{
		//вкарваме елементи във времения стек докато не срещнем затваряща скоба
		while (!strStack.empty() && strStack.top() != ")")
		{
			tempStack.push(strStack.top());
			if (!strStack.empty())
				strStack.pop();
			else break;
		}

		//премахваме затваряшата скоба от стека
		if (!strStack.empty())
			strStack.pop();

		if (!tempStack.empty())
		{
			string first = tempStack.top();
			tempStack.pop();
			if (!tempStack.empty())
			{
				if (tempStack.top() == "(")
					tempStack.pop();

				string second = tempStack.top();
				tempStack.pop();

				int num = atoi(second.c_str());

				string calculated = "";
				for (size_t i = 0; i < num; i++)
				{
					calculated += first;
				}

				//ако на върха на временния стек има Символи ги залепяме към calculated
				if (!tempStack.empty() && tempStack.top() != "(" && tempStack.top() != ")")
				{
					string top = tempStack.top();
					calculated = top + calculated;
					tempStack.pop();
				}

				//когато няма други елементи в изходния стек връщаме резултата
				if (strStack.count() == 0)
					return calculated;

				strStack.push(calculated);

				while (!tempStack.empty() && tempStack.top() != "")
				{
					strStack.push(tempStack.top());
					tempStack.pop();
				}
			}
			else
				return first;
		}
	}
	return "";
}

int main()
{
	string str = "", num;
	char prevChar = ' ';

	//string input = "AB";
	//string input = "12(ZQ)";
	//string input = "3(AB2(CD))";
	//string input = "2(2(A)3(B))";

	string input;
	cout << "Input string: ";
	cin >> input;

	Stack<string> strStack = Stack<string>::Stack(input.length() * 2);

	for (size_t i = 0; i < input.length(); i++)
	{
		char currentChar = input[i];

		switch (TypeOfChar(currentChar))
		{
		case 1:
			if (TypeOfChar(prevChar) != 1 && str.length() > 0)
			{
				strStack.push(str);
				str = currentChar;
			}
			else
				str += currentChar;
			break;
		case 2:
			if (TypeOfChar(prevChar) != 2 && str.length() > 0)
			{
				strStack.push(str);
				str = currentChar;
			}
			else
				str += currentChar;
			break;
		case 3:
			strStack.push(str);
			str = currentChar;
			break;
		case 4:

			strStack.push(str);
			str = currentChar;
			break;
		}
		prevChar = currentChar;
	}

	if (str.length() > 0)
		strStack.push(str);

	cout << "Output: \n";
	string output = Print(strStack);
	cout << output << endl;

	return 0;
}