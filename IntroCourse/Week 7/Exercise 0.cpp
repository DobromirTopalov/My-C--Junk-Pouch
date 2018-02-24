/*Зад.0
Да се състави програма на C++, която проверява има ли определена цифра във вече въведено число.*/

#include <iostream>

bool isThere(int num,int digit)
{
	while (num)
	{
		if (num % 10 == digit)
		{
			return true;
		}
		num /= 10;
	}

	return false;
}

int main()
{
	int number,digit;
	std::cin >> number >> digit;
	std::cout << std::boolalpha << isThere(number, digit) << "\n";

	return 0;
}