/*Зад.7
Да се напише функция, която "изтрива" елемент от масив на указана позиция. Последния елемент бива "загубен".
Последния елемент да се занули.*/

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

int* deletearr(int* arr, int element, int size, int index)
{
	int* newarr = new int[size];
	for (int i = 0; i < index; i++)
	{
		newarr[i] = arr[i];
	}
	for (int i = index, p = index + 1; i < size - 1; i++, p++)
	{
		newarr[i] = arr[p];
	}

	newarr[size-1] = 0;
	return newarr;
}

int main()
{
	int const size = 7;
	int arr[size];
	int*arr2;
	fillarr(arr, size);
	printarr(arr, size);
	std::cout << "\n";
	arr2 = deletearr(arr, 99, size, 3);
	printarr(arr2, size);

	std::cout << "\n";
	return 0;
}