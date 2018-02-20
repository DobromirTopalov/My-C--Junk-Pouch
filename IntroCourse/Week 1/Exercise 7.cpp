/*Зад.7
Напишете програма, която намира периметъра и лицето на триъгълник по зададени дължините на 3-те му страни.*/

#include <iostream>
#include <cmath>

int main()
{
	float a, b, c, area, perimeter,halfper;
	std::cin >> a >> b >> c;
	perimeter = a + b + c;
	halfper = perimeter / 2;
	area = sqrt(halfper*(halfper - a)*(halfper - b)*(halfper - c));

	std::cout << "The area and perimeter of triangle:\n";
	std::cout << area<<" / "<<perimeter<<"\n";
	


	return 0;
}