/*���.1
�� �� �������� ���� �������� ���� ����� �� ���� ������������ �� 2 � �� 3 � �� �� ���� �� 5.*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	if (number % 2 == 0 && number % 3 == 0 && number % 5 != 0)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}


	return 0;
}