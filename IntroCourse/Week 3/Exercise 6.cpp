/*���.6
�������� ��������, ����� ��������� ���� ����� ���������� � ����������� �� ������ 3 ������.*/

#include <iostream>

int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;

	if ((b*b + a*a) == c*c)
	{
		std::cout << "Yes!\n";
	}
	else
	{
		std::cout << "No!\n";
	}


	return 0;
}