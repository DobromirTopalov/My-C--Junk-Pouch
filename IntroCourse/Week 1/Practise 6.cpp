/*���.6
�� � �������� ���� �� ����� � ������ ���������� ���� ����� x � y, ���� � �����, ������ �� ����������� � ������ (0,0) � ������ 5.*/

#include <iostream>
#include <cmath>

int main()
{
	int x, y, xc, yc, r;
	xc = 0;
	yc = 0;
	r = 5;

	std::cin >> x >> y;

	if (sqrt(pow(x - xc, 2) + pow(y - yc, 2))<r)
	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}

	return 0;
}