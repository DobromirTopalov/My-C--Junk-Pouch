/*���.5
�������� ��������, ����� ��������� ���� ������� ������ � �����, ����� ��� ������ ����� � ������� ��������� ���������
��� ����� �� ��������.*/

#include <iostream>

int main()
{
	char sign;
	std::cin >> sign;

	if ((sign >= 'a'&&sign <= 'z'))
	{
		std::cout << "It is a lowercase letter!\n";
	}
	else if (sign >= 'A'&&sign <= 'Z')
	{
		std::cout << "It is a uppercase letter!\n";
	}
	else if (sign >= '0'&&sign <= '9')
	{
		std::cout << "It is a digit!\n";
	}

	return 0;
}