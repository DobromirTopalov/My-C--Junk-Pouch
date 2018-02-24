/*Зад.6
Да се напише функция, която "вмъква" нов елемент в масив на указана позиция. Последния елемент бива "загубен".*/

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

int* insert(int* arr,int element, int size, int index)
{
	int* newarr = new int[size];
	for (int i = 0; i < index; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[index] = element;
	for (int i = index,p=index+1; i < size-1; i++,p++)
	{
		newarr[p] = arr[i];
	}
	
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
	arr2=insert(arr, 99, size, 3);
	printarr(arr2, size);

	std::cout << "\n";
	return 0;
}