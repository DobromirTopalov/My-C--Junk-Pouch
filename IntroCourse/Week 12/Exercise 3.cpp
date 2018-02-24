/*Зад.3
Да се напише функция, която търси даден елемент в масив и връща първия индекс на който се среща. Ако елемента го няма в масива - 
да върне -1*/

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

int find(int arr[], int elemnt, int left, int right)
{
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == elemnt)
		{
			return mid;
		}
		else if (arr[mid] > elemnt)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int const size = 7;
	int arr[size];
	fillarr(arr, size);
	Ssort(arr, size);
	int a;
	std::cout << "\nFind: ";
	std::cin >> a;
	std::cout<<find(arr, a, 0, size);
	//printarr(arr, size);
	std::cout << "\n";

	return 0;
}