//Напишете програма, която чете от конзолата цяло положително число N, където
//2 < N < 128 и след това създава матрица с размер NxN, която съдържа числата от 1 до N^2.
//Обходете матрицата, започвайки от горният ляв ъгъл, спираловидно и изведете резултата на
//екрана.
#include <iostream>
using namespace std;

void spiralViewArray(int rows, int column, int arr[][128])
{
	int i, startRow = 0, endColumn = 0;

	while (startRow < rows && endColumn < column)
	{
		//Печатане на първия пореден ред
		for (i = endColumn; i < column; ++i)
		{
			cout << arr[startRow][i] << " ";
		}
		startRow++;

		//Печатане на последната поредна колонка
		for (i = startRow; i < rows; ++i)
		{
			cout << arr[i][column - 1] << " ";
		}
		column--;

		//Печатане на последния пореден ред
		if (startRow < rows)
		{
			for (i = column - 1; i >= endColumn; --i)
			{
				cout << arr[rows - 1][i] << " ";
			}
			rows--;
		}

		//Печатане на първата поредна колонка
		if (endColumn < column)
		{
			for (i = rows - 1; i >= startRow; --i)
			{
				cout << arr[i][endColumn] << " ";
			}
			endColumn++;
		}
	}
}

int main()
{
	int arr[128][128], n, p = 0;

	//Проверка на входните данни
	do
	{
		cout << "n=";
		cin >> n;
	} while (n < 2 && n>128);

	//Попълване на масива
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p++;
			arr[i][j] = p;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

