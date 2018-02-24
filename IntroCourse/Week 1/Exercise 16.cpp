/*«ад.16
ƒа се напише булев израз, който провер€ва дали дадена година е високосна.*/

#include <iostream>

int main()
{
	int year;
	std::cin >> year;

	/*Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100,
	but these centurial years are leap years if they are exactly divisible by 400.For example, the years 1700, 1800, 
	and 1900 are not leap years, but the years 1600 and 2000 are.*/
	
	bool leapYear = ((year % 4 == 0 && year%100!=0) || (year % 400 == 0 && year % 100 == 0));
	if (leapYear == 1)
	{
		std::cout << "A LEAP YEAR \n";
	}
	else
	{
		std::cout << "A common YEAR \n";
	}


	return 0;
}