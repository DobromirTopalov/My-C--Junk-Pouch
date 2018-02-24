/*Зад.1
Проверете дали редицата от числата е строго растяща.*/

#include <iostream>

bool isgrowing(double arr[])
{
	bool isGrow = false;
	for (int i = 0; i < 5-1; i++)
	{
		
		if (arr[i] <= arr[i + 1])
		{
			isGrow = true;
		}
		else
		{
			isGrow = false;
			break;
		}
	}
	return isGrow;
}

int main()
{
	double arr[] = { 2.0,8.7,4.2,1.4,3.36 };
	double arr2[] = { 2.0,8.7,14.20,21.4,33.36 };
	std::cout << std::boolalpha<<isgrowing(arr2)<< "\n";


	return 0;
}