/*���.6
�� �� ������� ��������, � ����� ������������ ������� ���������� ����� � ������� �������� ��������.*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;

	for (int i = 1; i <= number; i++)
	{
		if (number%i == 0)
		{
			std::cout << i << " ";
		}
	}
	std::cout << "\n";

	return 0;
}