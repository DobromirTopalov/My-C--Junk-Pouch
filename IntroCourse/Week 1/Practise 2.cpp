/*���.2
�� �� �������� ������������� �� ��������� ��������� � �� �� �������� ���� �� ��� ������ ������ � ����� �� ���� �� �� - 1 ��� 2 
(��������, �� �� ����� � ���������� ��������������� �� ����������� �� � >= 0).
*/

#include <iostream>

int main()
{
	float a, b, c, D;
	std::cin >> a >> b >> c;
	D = (b*b) - (4 * a*c);

	if (D > 0)
	{
		std::cout << "equation has 2 real roots \n";
	}
	else if (D == 0)
	{
		std::cout << "equation has 1 real root \n";
	}
	else
	{
		std::cout << "equation has no answer \n";
	}


	return 0;
}