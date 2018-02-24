/*Зад.4
Да се напише функция, която копира елементите от един масив в друг подаден масив.*/

#include <iostream>

void fillarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

void copy(int arr[], int arr2[],int size)
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr[i];
	}
}

int main()
{
	int const size = 7;
	int arr[size];
	int arr2[size];
	fillarr(arr,size);
	printarr(arr, size);
	std::cout << "\n";
	copy(arr, arr2, size);
	printarr(arr2, size);
	std::cout << "\n";

	return 0;
}