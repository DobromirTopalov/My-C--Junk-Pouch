/*Зад.2
Да се напише функция, която сортира елементите на масив във възходящ ред.*/

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

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Ssort(int arr[], int size)
{
	int minimal;
	for (int i = 0; i < size; i++)
	{
		minimal = i;
		for (int j = i; j < size; j++)
		{
			if (arr[j] < arr[minimal])
			{
				minimal = j;
			}
		}
		swap(arr[i], arr[minimal]);
	}
}


int main()
{
	int const size = 7;
	int arr[size];
	fillarr(arr, size);
	Ssort(arr, size);
	printarr(arr, size);
	std::cout << "\n";

	return 0;
}