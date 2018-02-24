/*Зад.0
Да се напише функция, която извежда елементите на масив на стандартния изход.*/

#include <iostream>

void printarr(int arr[],int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i]<<" ";
	}
}

int main()
{
	int arr[] = { 1,23,5,-1,0,4,6 };
	int size = 7;
	printarr(arr, size);
	std::cout << "\n";

	return 0;
}