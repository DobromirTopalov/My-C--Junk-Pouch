/*Зад.8
Да се състави програма (C++), чрез която се въвежда естествено число N от интервала [5..25]. Да се въведат N броя двуцифрени естествени
числа. Програмата да използва само един масив и да илюстрира алгоритъм за изтриване на елемент при работа с масив.*/


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

void deletearr(float arr[], int n,int index)
{
	for (int i = index; i < n-1; i++)
	{
		arr[i] = arr[i + 1];
	}
}

int main()
{
	float arrone[1000];
	
	int number;
	std::cin >> number;

	if (number >= 5 && number <= 25)
	{
		fillarr(arrone, number);
		printarr(arrone, number);
		deletearr(arrone, number, 2);
		printarr(arrone, number-1);
	}

	return 0;
}