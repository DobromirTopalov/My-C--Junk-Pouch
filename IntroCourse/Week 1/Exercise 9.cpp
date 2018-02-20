/*Зад.9
Напишете програма, която намира и извежда периметъра и лицето на триъгълник по зададени координати на трите му върха.*/

#include <iostream>
#include <cmath>

int main()
{
	int xA, yA, xB, yB, xC, yC;
	std::cin >> xA >> yA >> xB >> yB >> xC >> yC;
	
	int AB, BC, AC;
	AB = sqrt((xB - xA) + (yB - yA));
	BC = sqrt((xC - xB) + (yC - yB));
	AC = sqrt((xC - xA) + (yC - yA));
	
	int area, perimeter, halfper;
	perimeter = AB + BC + AC;
	halfper = perimeter / 2;
	area = sqrt(halfper*(halfper - AB)*(halfper - BC)*(halfper - AC));

	std::cout << "Perimeter is: " << perimeter<<"\n";
	std::cout << "Area is: " << area << "\n";


	return 0;
}