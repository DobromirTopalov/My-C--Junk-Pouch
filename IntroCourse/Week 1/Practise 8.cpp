/*Зад.8
Да се определи дали точка (x, y) лежи в оцветената област от фигурата. */

#include <iostream>
#include <cmath>

int main()
{
	int x, y, xc, yc, xc2, yc2, r, r2;
	xc = 0;
	yc = 0;
	r = 2;
	xc2 = 0;
	yc2 = 3;
	r2 = 1;

	std::cin >> x >> y;

	if ((sqrt(pow(x - xc, 2) + pow(y - yc, 2))<r) || (sqrt(pow(x - xc2, 2) + pow(y - yc2, 2))<r2))

	{
		std::cout << "true\n";
	}
	else
	{
		std::cout << "false\n";
	}


	return 0;
}