/*���.1
�� �� ������ �������, ����� ������ ���� ��������� �� ��� int � ����� ������ �� ������ ���������� ����� �� ���������� ����
��������� �����(�����������).*/

#include <iostream>

int sum(int n)
{
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	return sum;
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << sum(number) << "\n";

	return 0;
}