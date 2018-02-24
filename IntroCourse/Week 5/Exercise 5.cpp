/*Зад.5
От 3- цифрено естествено число можем да сформираме 3 отделни 2-цифрени числа по следния начин 1 и 2 цифра, 1 и 3 цифра,
2 и 3 цифра. Трябва да се провери дали едно от тези числа е равно на сумата от останалите две. Да се състави програма,
която извежда всички 3-цифрени естествени числа >= от въведеното 3-цифрено, които отговарят на това условие.*/

#include <iostream>

int main()
{
	int number = 1;
	std::cin >> number;

	int first = number / 10;
	int second = (number / 100) * 10 + number % 10;
	int third = number % 100;

	int bignumber;
	if (first == second + third)
	{
		bignumber = second * 10 + third;
	}
	else if (second == first + third)
	{
		bignumber = first * 10 + third;
	}
	else if (third == first + second)
	{
		bignumber = first * 10 + second;
	}



	for (int i = 100; i < 1000; i++)
	{
		int first = i / 10;
		int third = i % 100;
		int second = (first / 100) * 10 + i % 10;


		if (first == second + third)
		{
			int tempor = (second * 10 + third);
			if (tempor >= bignumber)
			{
				std::cout << tempor << " ";
				continue;
			}
		}
		else if (second == first + third)
		{
			int tempor = (first * 10 + third);
			if (tempor >= bignumber)
			{
				std::cout << tempor << " ";
				continue;
			}
		}
		else if (third == first + second)
		{
			int tempor = (first * 10 + second);
			if (tempor >= bignumber)
			{
				std::cout << tempor << " ";
				continue;
			}
		}
	}

	std::cout << "\n";

	return 0;
}