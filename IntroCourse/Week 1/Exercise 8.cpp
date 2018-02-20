/*Зад.8
Напишете програма, която пресмята разстоянието между 2 точки, зададени с техните координати.*/

#include <iostream>
#include <cmath>

int main()
{
	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	std::cout << "The distance between your points = ";
	std::cout << sqrt((x2 - x1) + (y2 - y1));
	std::cout << "\n";



	return 0;
}