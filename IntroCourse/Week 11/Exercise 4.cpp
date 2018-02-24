/*Зад.4
Да се напише функция, която приема двумерен масив и извежда елементите чрез спираловидно обхождане.*/

#include <iostream>
const int SIZE = 5;

void fillarr(int arr[][SIZE]);
void printBottom(int arr[][SIZE], int x1, int y1, int x2, int y2);
void printTop(int arr[][SIZE], int x1, int y1, int x2, int y2);
void spiral(int arr[][SIZE]);

int main()
{
	int arr[SIZE][SIZE];
	fillarr(arr);
	spiral(arr);

	return 0;
}


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

void printBottom(int arr[][SIZE], int x1, int y1, int x2, int y2)
{
	for (int i = x2; i >= x1; i--) 
	{
		std::cout << arr[y2][i];
	}

	for (int j = y2 - 1; j >= y1; j--) 
	{
		std::cout << arr[j][x1];
	}

	if (x2 - x1 > 0) 
	{
		printTop(arr, x1 + 1, y1, x2, y2 - 1);
	}
}

void printTop(int arr[][SIZE], int x1, int y1, int x2, int y2) 
{
	for (int i = x1; i <= x2; i++) 
	{
		std::cout << arr[y1][i];
	}

	for (int j = y1 + 1; j <= y2; j++) 
	{
		std::cout << arr[j][x2];
	}

	if (x2 - x1 > 0) 
	{
		printBottom(arr, x1, y1 + 1, x2 - 1, y2);
	}
}


void spiral(int arr[][SIZE]) 
{
	printTop(arr, 0, 0, SIZE - 1, SIZE - 1);
}
