/*Зад.0
Да се напише програма, в която потребителят въвежда оценка от 2 до 6 и извежда на екрана оценката с думи[Пример: Вход '2', Изход 'Слаб'].*/

#include <iostream>

int main()
{
	int grade;
	std::cin >> grade;

	if (grade >= 2 && grade <= 6)
	{
		switch (grade)
		{

		case 2:	std::cout << "Week!\n"; break;
		case 3:	std::cout << "Average!\n"; break;
		case 4:	std::cout << "Good!\n"; break;
		case 5:	std::cout << "Very Good!\n"; break;
		case 6:	std::cout << "Excelence!\n"; break;
		default: std::cout << "Anti-Conti\n"; break;

		}
	}
	else
	{
		std::cout << "Incorrect input!\n";
	}

	return 0;
}