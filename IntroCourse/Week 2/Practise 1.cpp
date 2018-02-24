/*Зад.1
Да се напише програма, в която потребителя въвежда оценка по програмиране от 0 до 100 и ако е получил максимум точки, 
да се изведе подходящо съобщение на екрана.*/

#include <iostream>

int main()
{
	int grade;
	std::cin >> grade;

	if (grade >= 0 && grade <= 100)
	{
		if (grade == 100)
		{
			std::cout << "Yoahaoooo 100 points !!! \n";
		}
		else
		{
			;
		}
	}
	else
	{
		;
	}

	return 0;
}