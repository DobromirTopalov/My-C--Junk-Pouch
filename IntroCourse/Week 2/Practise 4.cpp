/*���.4
�� �� ������ ��������, � ����� ����������� ������� ������ � �������� ���� �� � ���������.*/

#include <iostream>

int main()
{
	int year;
	std::cin >> year;

	bool leapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0));
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