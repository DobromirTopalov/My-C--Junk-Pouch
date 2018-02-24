/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 6
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>

void fillList(double arr[][3], int rows, int columns);
void printList(double arr[][3], int rows, int columns);
void sortListByFN(double arr[][3], int rows, int columns);
void sortListByN(double arr[][3], int rows, int columns);


void fillList(double arr[][3], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}


void printList(double arr[][3], int rows, int columns)
{
	for (int i = 0; i<rows; i++)
	{
		for (int j = 0; j<columns; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void sortListByFN(double arr[][3], int rows, int columns)
{
	double minNum;
	double swap;
	int k = 0;
	int counter = 0;

	for (int i = 0; i<rows; i++)
	{
		k = i;
		minNum = arr[i][0];
		for (int i = k; i<rows; i++)
		{
			if (minNum >= arr[i][0])
			{
				minNum = arr[i][0];
				counter = i;
			}
		}

		for (int j = 0; j < columns; j++)
		{
			swap = arr[i][j];
			arr[i][j] = arr[counter][j];      //(=minNum)
			arr[counter][j] = swap;
		}

		counter = 0;
	}
}

void sortListByN(double arr[][3], int rows, int columns)
{
	double numberToCompare;
	double taskOfNumberToCompare;
	int k = 0;
	double swap;
	int index = 0;;

	for (int i = 0; i < rows; i++)
	{
		numberToCompare = arr[i][0];
		taskOfNumberToCompare = arr[i][1];
		k = i;
		for (int i = k; i < rows; i++)
		{
			if (numberToCompare == arr[i][0])
			{
				if (taskOfNumberToCompare >= arr[i][1])
				{
					//numberToCompare = arr[i][0];
					taskOfNumberToCompare = arr[i][1];
					index = i;
				}
			}
			if (numberToCompare != arr[i][0])
			{
				continue;
			}
		}
		for (int j = 0; j < columns; j++)
		{
			swap = arr[i][j];
			arr[i][j] = arr[index][j];      //(=minNum)
			arr[index][j] = swap;
		}
		index = 0;
	}
}


int main()
{
	int rows;
	int columns = 3;
	std::cin >> rows;
	double list[10000][3];
	bool breakit = false;
	bool breakit2 = false;

	fillList(list, rows, columns);

	for (int i = 0; i < rows; i++)
	{

		if ((list[i][0] > 0 && list[i][0] <= 1000000) == false)
		{
			breakit = true;
			if (breakit == true)
			{
				break;
			}
		}
	}

	for (int i = 0; i < rows; i++)
	{
		if ((list[i][1] >= 1 && list[i][1] <= 10) == false)
		{
			breakit2 = true;
			if (breakit2 == true)
			{
				break;
			}
		}
	}
	if (breakit == false && breakit2 == false)
	{
		sortListByFN(list, rows, columns);
		sortListByN(list, rows, columns);
		printList(list, rows, columns);
	}
	else
	{
		;
	}

	return 0;
}