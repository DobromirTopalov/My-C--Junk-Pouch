/*���.3
�������� ����� �� ��������� � ������ �������� ����� ��������� 1-I, 5-V, 10-X, 50-L, 100-C, 500-D � 1000-M.
�� �� ������� ��������, ����� �� �������� ����� �� ���������� ������� ����������� �����.*/

#include <iostream>

int main()
{
	char sign;
	std::cin >> sign;

	switch (sign)
	{

	case 'I':	std::cout << "1!\n"; break;
	case 'V':	std::cout << "5!\n"; break;
	case 'X':	std::cout << "10!\n"; break;
	case 'L':	std::cout << "50!\n"; break;
	case 'C':	std::cout << "100!\n"; break;
	case 'D':	std::cout << "500!\n"; break;
	case 'M':	std::cout << "1000!\n"; break;


	default: std::cout << "Wrong input\n"; break;

	}
	

	return 0;
}