/*���.7
�� ������ ���������� (x, y) - ���� �����, �� ����� ���������,�� �� �������� � ��� �������� ���� �������. 
��� ���� �� ����� �� ������������� ���, ���� �� �� ������.*/

#include <iostream>

int main()
{
	int x, y, xc, yc;
	xc = 0;
	yc = 0;

	std::cin >> x >> y;

	if (x > xc && y > yc)
	{
		std::cout << "I quadrant \n";
	}
	else if (x < xc && y > yc)
	{
		std::cout << "II quadrant \n";
	}
	else if (x < xc && y < yc)
	{
		std::cout << "III quadrant \n";
	}
	else if (x > xc && y < yc)
	{
		std::cout << "IV quadrant \n";
	}
	else if (x == xc && (y < yc || y > yc))
	{
		std::cout << "on Oy axis \n";
	}
	else if ((x < xc || x > xc) && y == yc)
	{
		std::cout << "on Ox axis \n";
	}
	else
	{
		;
	}

	return 0;
}