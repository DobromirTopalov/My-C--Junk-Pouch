/*���.2

�� �� ������� ��������, ���� ����� ������������ �������
���������� ����� � ������� ������ ������� � �� ������� �� ������ � ��������� ������ �������. �� �� �������� while �����.*/


#include <iostream>
#include <cmath>

int main()
{
	int number;
	std::cin >> number;
	
	int decimalNumber = 0, i = 0, remainder;
	while (number)
	{
		remainder = number % 10;
		number /= 10;
		decimalNumber += remainder*pow(2, i);
		++i;
	}

	std::cout << decimalNumber << "\n";

	return 0;
}