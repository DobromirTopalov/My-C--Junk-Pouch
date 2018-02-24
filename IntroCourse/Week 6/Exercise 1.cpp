/*Зад.1
Да се напише функция, която приема един параметър от тип int и връща сумата на всички естествени числа до подаденото като
параметър число(включително).*/

#include <iostream>

int sum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << sum(number) << "\n";

	return 0;
}