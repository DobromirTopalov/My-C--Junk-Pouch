/*Зад.0
Да се напише функция, която приема матрица и извежда елементите по главния диагонал.*/

#include <iostream>
const int SIZE = 5;

void fillarr(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void printarr(int arr[][SIZE])
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i][i]<<" ";
	}
	std::cout << "\n";
}

int main()
{
	int arr[SIZE][SIZE];
	fillarr(arr);
	printarr(arr);

	return 0;
}