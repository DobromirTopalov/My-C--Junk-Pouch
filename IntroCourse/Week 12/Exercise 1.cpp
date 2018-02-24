/*Зад.1
Да се напише функция, която запълва масив с дадена стойност.*/

#include <iostream>

void fillarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin>> arr[i];
	}
}

void printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int main()
{
	int const size = 7;
	int arr[size];
	fillarr(arr, size);
	printarr(arr, size);
	std::cout << "\n";

	return 0;
}