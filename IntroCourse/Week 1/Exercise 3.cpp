/*���.3
�������� ��������, ����� �� ����� ������ �������� ������ �� ����� � ��������� �� ����������� ��� ��������� ������.*/

#include <iostream>

int main()
{
	double rad, area, perimeter;
	const double PI = 3.14159265359;
	std::cin >> rad;
	area = rad*rad*PI;
	perimeter = PI * 2 * rad;

	std::cout << "The area of your circle is: " << area << " and the perimeter is: " << perimeter << "\n";




	return 0;
}