/*Зад.10
Една редица от естествени числа ще наричаме зигзагообразна нагоре, ако за елементите й са изпълняват условията:
N1 < N2 > N3 < N4 > N5 <.. Съставете програма (C++), която проверява дали въведени в едномерен масив редица от числа изпълняват 
горните изисквания.*/

#include <iostream>

void fillarr(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void printarr(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

bool ziggy(float arr[], int n)
{
	bool iszigg = false;
	for (int i = 0; i < n-2; i+=2)
	{
		iszigg = false;
		if ((arr[i] < arr[i + 1])&&(arr[i+1]>arr[i+2]))
		{
			iszigg = true;
		}
		else
		{
			iszigg = false;
			break;
		}

	}
	return iszigg;
}

int main()
{
	float arrone[1000];
	int number;
	std::cin >> number;

	if (number >= 1 && number <= 1000)
	{
		fillarr(arrone, number);
		std::cout << std::boolalpha << ziggy(arrone, number) << "\n";
	}

	return 0;
}