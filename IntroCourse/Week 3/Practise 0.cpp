/*���.0
�� �� ������ ��������, � ����� ������������ ������� ������ �� 2 �� 6 � ������� �� ������ �������� � ����[������: ���� '2', ����� '����'].*/

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