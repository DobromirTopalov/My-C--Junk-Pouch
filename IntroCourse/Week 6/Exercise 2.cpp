/*���.2
�� �� ������ �������, ����� ������ ���������� ����� ���� ��������� � ����� ��������� �� ���� �����.*/


#include <iostream>

int factorial(int n)
{
	int result = n;
	if (n == 0)
	{
		return 1;
	}
	else
	{
		result*=factorial(n - 1);
	}
	return result;
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << factorial(number) << "\n";

	return 0;
}