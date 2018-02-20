/*Зад.7
Напишете програма, която извежда броя на дните на даден месец. Програмата приема месец (цяла стойност между 1 и 12) и година.
За неправилни входни данни изведете грешка.*/

#include <iostream>

int main()
{
	int month;
	int year;
	std::cin >> month >> year;
	
	if (month >= 0 && month <= 12 && year >= 0)
	{
		switch (month)
		{
		case 1:	std::cout << "January has 31days!\n"; break;
		case 2:

			if ((year % 4 == 0) || (year % 400 == 0) && (year % 100 != 0))
			{
				std::cout << "February has 29days!\n";
			}
			else
			{
				std::cout << "February has 28days!\n";
			}
			break;
		case 3:		std::cout << "March has 31days!\n"; break;
		case 4:		std::cout << "April has 30days!\n"; break;
		case 5:		std::cout << "May has 31days!\n"; break;
		case 6:		std::cout << "June has 30days!\n"; break;
		case 7:		std::cout << "July has 31days!\n"; break;
		case 8:		std::cout << "August has 31days!\n"; break;
		case 9:		std::cout << "September has 30days!\n"; break;
		case 10:	std::cout << "October has 31days!\n"; break;
		case 11:	std::cout << "November has 30days!\n"; break;
		case 12:	std::cout << "December has 31days!\n"; break;

		}
	}
	else
	{
		std::cout << "Incorrect input!\n";
	}

	return 0;
}