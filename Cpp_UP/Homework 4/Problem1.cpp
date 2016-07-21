#include<iostream>
#include<cctype>
using namespace std;

void InputArray(char arr[][100], int cols, int rows)
{
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			cout << "Input letter:";
			cin >> arr[i][j];
		}
	}	
}

bool SearchWord(char arr[][100], char word[], int cols, int rows)
{
	bool isHave;
	int wordLenght = strlen(word);

	//хоризонтално
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < wordLenght; j++)
		{
			if (arr[i][j] == word[j])
				isHave = true;
			else isHave = false;
		}
	}
	//вертикално
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < wordLenght; j++)
		{
			if (arr[i][j] == word[j])
				isHave = true;
			else isHave = false;
		}
	}

	return isHave;
}

int main()
{
	int cols=0, rows=0;
	char arr[100][100], word[100];
	
	//Въвеждане елементите на масива 
	//Броя на колоните
	do{
		cout << "cols: ";
		cin >> cols;
	} while (cols<3 || cols>100);
	//Броя на редовете
	do{
		cout << "rows: ";
		cin >> rows;
	} while (rows<3 || rows>100);

	//Въвеждане елементите на масива
	InputArray(arr, cols, rows);

	//Броя на думите, които ще търсим
	int cntWords = 0;
	cout << "Count words:";
	cin >> cntWords;

	//Обхождане според броя на търсените думи
	do
	{
		cout << "Word:";
		cin>>word;
		//Проверка за думата в масива
		if (SearchWord(arr, word, cols, rows))
			cout << "YES!" << endl;
		else cout << "NO!"<<endl;

		cntWords--;
	} while (cntWords > 0);

	return 0;
}