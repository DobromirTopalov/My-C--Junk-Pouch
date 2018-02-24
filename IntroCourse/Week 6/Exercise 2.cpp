/*Зад.2
Да се напише функция, която приема естествено число като параметър и връща факториел от това число.*/


#include <iostream>

int factorial(int n)
{
	int result = n;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result*=factorial(n - 1);
	}
	return result;
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << factorial(number) << "\n";

	return 0;
}