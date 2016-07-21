#include<iostream> 
#include<cctype>
#include<string>

using namespace std;

string ReverseString(string word){
	if (word.length() == 1) {
		return word;
	}
	else{
		return ReverseString(word.substr(1, word.length())) + word.at(0);
	}
}

int main()
{
	//Броя на думите в речника
	int n,d=0;
	cout << "N=";
	cin >> n;

	string str;
	string *dictionary = new string[n];
	string *words = new string[];
	string  result,word;
	
	//Добавяне на думите в речника
	for (int i = 0; i < n; i++)
	{
		do{
			cout << "Input word in dictionary: ";
			cin >> dictionary[i];
		} while (dictionary[i].length() > 16);
	}

	//Въввеждане на стринг
	cout << "Str:";
	cin >> str;

	//Разделяне стринга на думи и добавяне на думите в масив
	for (int i = 0; i <= str.length(); i++)
	{
		if (str[i] == ' ')
		{
			words[i] = str[i-d];
			d = i;
		}
	}

	//Търсене на думте от стронга в речника
	for (int i = 0; i < words[i].length(); i++)
	{
		for (int j = 0; j < dictionary[i].length(); j++)
		{
			//При намиране на думата се обръща и се добавя към крйния резултат
			if (words[i].compare(dictionary[i]))
				result += ReverseString(words[i]);			
		}
	}
	return 0;
}