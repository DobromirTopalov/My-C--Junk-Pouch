/*���.11
�������� ��������, ����� ������ ������ �� ������� �� ������ ���������� �����.*/

#include <iostream>

int main()
{

	int number,sum;
	std::cin >> number;
	sum = (number / 100) + ((number / 10) % 10) + (number % 10);
	std::cout << "The sum of digits = " << sum << "\n";


	return 0;
}