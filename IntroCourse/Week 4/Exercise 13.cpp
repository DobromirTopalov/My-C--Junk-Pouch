/*���.13
�� �� ������ ��������, ����� ������ ���� ����� � ������ ������������ ��.*/

#include <iostream>
#include <cmath>

int symetric(int n)
{
	int tempor,result=0;
	int digit;
	int size = (int)log10((double)abs(n) + 1)+1;
	for (int i = size-1; i >= 0; i--)
	{
		digit = n % 10;
		tempor =digit*pow(10, i);
		result += tempor;
		n /= 10;

	}
	return result;
}

int main()
{
	int number;
	std::cin >> number;
	std::cout << symetric(number) << "\n";

	return 0;
}