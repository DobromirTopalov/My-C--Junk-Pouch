/*���.10
�������� ��������, ����� ������ � ������� ������������ �� ����������� �� ���������� �� �������� ���������� �� ����� �� �����.*/

#include <iostream>

int main()
{
	int xA, yA, xB, yB, xC, yC;
	std::cin >> xA >> yA >> xB >> yB >> xC >> yC;
	int xM, yM;
	xM = (xA + xB + xC) / 3;
	yM = (yA + yB + yC) / 3;

	std::cout << "The coordinates of centroid are:(" << xM << ";" << yM << ")\n";


	return 0;
}