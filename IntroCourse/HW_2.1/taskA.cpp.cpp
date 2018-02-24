/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 2A
* @compiler VC
*
*/

#include <iostream>

//returns sum of elements in mainDiagonal
int mainCorner(int* arr, unsigned short size, unsigned short MAX_SIZE);

//returns sum of elements in secondDiagonal
int secondCorner(int* arr, unsigned short size, unsigned short MAX_SIZE);

//returns sum of elements in specific col
int cols(int* arr, unsigned short size, unsigned short MAX_SIZE, unsigned short start);

//returns sum of elements in specific row
int rows(int* arr, unsigned short size, unsigned short MAX_SIZE, unsigned short start);

//compares all the information for MAGICTABLE
bool checkIsMagical(int* arr, unsigned short size, unsigned short MAX_SIZE, int mainD, int secondD);


int main()
{
	unsigned short tableSize;
	std::cin >> tableSize;

	//input check
	if (tableSize <= 0 || tableSize > 10)
	{
		std::cout << "Size not allowed!\n";
		return 1;
	}

	//allocate space for array
	const unsigned short MAX_ELEMENTS = tableSize*tableSize;
	int* arrayOfElements = new int [MAX_ELEMENTS];
	
	//fill array with something
	for (int i = 0; i < MAX_ELEMENTS; i++)
	{
		std::cin >> arrayOfElements[i];
	}
	
	//get information for diagonals since they are unique and we calculate them once
		int mainDiagonal = mainCorner(arrayOfElements, tableSize, MAX_ELEMENTS);
		int secondDiagonal = secondCorner(arrayOfElements, tableSize, MAX_ELEMENTS);
		//

	//Final comparison 
	checkIsMagical(arrayOfElements, tableSize, MAX_ELEMENTS, mainDiagonal, secondDiagonal);

	delete[] arrayOfElements;
	return 0;
}

int mainCorner(int* arr, unsigned short size, unsigned short MAX_SIZE)
{
	int result = 0;
	int step = size + 1;

	for (int i = 0; i <= MAX_SIZE; i += step)
	{
		result += arr[i];
	}

	return result;
}

int secondCorner(int* arr, unsigned short size, unsigned short MAX_SIZE)
{
	int result = 0;
	int step = size - 1;

	for (int i = step; i < MAX_SIZE - step; i += step)
	{
		result += arr[i];
	}

	return result;
}

int cols(int* arr, unsigned short size, unsigned short MAX_SIZE, unsigned short start)
{
	int result = 0;
	int step = size;
	int end = MAX_SIZE - size + start;

	for (unsigned short i = start; i <= end; i += step)
	{
		result += arr[i];
	}

	return result;
}

int rows(int* arr, unsigned short size, unsigned short MAX_SIZE, unsigned short start)
{
	int result = 0;
	int step = 1;
	int end = start + size;

	for (unsigned short i = start; i < end; i += step)
	{
		result += arr[i];
	}

	return result;
}

bool checkIsMagical(int* arr, unsigned short size, unsigned short MAX_SIZE, int mainD, int secondD)
{
	bool isMagical = true;

	for (int i = 0; i < size; i++)
	{
		int colsResult = cols(arr, size, MAX_SIZE, i);
	
		for (int j = 0, starter = 0; j < size; j++, starter += size)
		{
			int rowsResult = rows(arr, size, MAX_SIZE, starter);
	
			if (!(colsResult == rowsResult && colsResult == mainD && colsResult == secondD))
			{
				isMagical = false;
				std::cout << "False!\n";
				return isMagical;
			}

		}

	}

	std::cout << "True!\n";
	return isMagical;

}