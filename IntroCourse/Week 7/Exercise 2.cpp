/*���.2
�� �� ������� �������� �� C++,���� ����� �� �������� ������� �� ����������� �� ����� 'Z'. 
���������� �� ������ ������ �������� ������� � ��� ������� �� ����������� ��.*/

#include <iostream>

void symbols()
{
	char sign;
	std::cin >> sign;

	if (sign != 'Z')
	{
		symbols();
		std::cout << sign;
	}
	else
	{
		std::cout << "Z";
	}
}

int main()
{
	symbols();
	std::cout << "\n";

	return 0;
}