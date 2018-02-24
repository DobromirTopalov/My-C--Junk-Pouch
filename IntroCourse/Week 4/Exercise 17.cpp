/*���.17
�� �� ������ ��������, ����� ������ ���� ����������� ����� � ������� �� ������ ����������� �� ���� ������������ �� ������ ���������.*/

#include <iostream>

void separation(int n)
{
	if (n % 2 == 0)
	{
		std::cout << "2";
		std::cout << "*";
		separation(n / 2);
	}
	else if (n % 3 == 0)
	{
		std::cout << "3";
		std::cout << "*";
		separation(n / 3);
	}
	else if (n % 5 == 0)
	{
		std::cout << "5";
		std::cout << "*";
		separation(n / 5);
	}
	else if (n % 7 == 0)
	{
		std::cout << "7";
		std::cout << "*";
		separation(n / 7);
	}
	
	

}

int main()
{
	int number;
	std::cin >> number;
	separation(number);

	std::cout << "\n";
	return 0;
}