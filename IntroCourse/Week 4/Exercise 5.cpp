/*���.5
�������� ��������, ����� �������� ���� ������ ����� � ������.*/


#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	int counter = 0;
	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0)
		{
			counter++;
		}
	}

	if (counter == 2)
	{
		std::cout << "Yes!\n";
	}
	else
	{
		std::cout << "No!\n";
	}

	return 0;
}