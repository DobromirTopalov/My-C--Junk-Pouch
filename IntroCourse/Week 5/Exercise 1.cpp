/*���.1
�� �� ������� ��������, ���� ����� ������������ ������� ���������� 
����� � ��������� ������ ������� � �� ������� �� ������ � ������� ������ �������. �� �� �������� while �����.*/

#include <iostream>
#include <cmath>

int main()
{
	int number;
	std::cin >> number;

	int binaryNumber = 0;
	int remainder, tens = 1;

	while (number)
	{
		remainder = number % 2;
		number /= 2;
		binaryNumber += remainder*tens;
		tens *= 10;
	std::cout << binaryNumber << "\n";
	}


	return 0;
}