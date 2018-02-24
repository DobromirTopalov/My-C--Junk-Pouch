/*Зад.3
Намерете броя на четните числа в редицата.*/


#include <iostream>

int evenNumber(int arr[])
{
	int counter = 0;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] % 2 == 0)
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	int arr[] = { 2,7,5,4,6,9 };
	std::cout << evenNumber(arr) << "\n";

	return 0;
}