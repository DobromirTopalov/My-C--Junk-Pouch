/*���.5
�� 3- ������� ���������� ����� ����� �� ���������� 3 ������� 2-������� ����� �� ������� ����� 1 � 2 �����, 1 � 3 �����,
2 � 3 �����. ������ �� �� ������� ���� ���� �� ���� ����� � ����� �� ������ �� ���������� ���. �� �� ������� ��������,
����� ������� ������ 3-������� ���������� ����� >= �� ���������� 3-�������, ����� ��������� �� ���� �������.*/

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