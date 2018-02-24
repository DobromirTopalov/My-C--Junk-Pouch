/*Зад.2
След като е въведена редицата, да се въведе още едно число x и да се провери дали редицата съдържа x.*/

#include <iostream>
void insertX(int arr[],int n)
{
	arr[6] = n;
}

bool isThere(int arr[], int n)
{
	for (int i = 0; i < 7; i++)
	{
		if (arr[i] == n)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int arr[10] = { 2,7,5,4,6,9 };
	int number;
	std::cin >> number;
	insertX(arr, number);
	std::cout << std::boolalpha << isThere(arr, number) << "\n";


	return 0;
}