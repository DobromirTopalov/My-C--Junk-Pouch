/*Зад.15
Да се напише булев израз, който проверява дали уравнението ax2 + bx + c = 0 има реални корени.*/

#include <iostream>

int main()
{
	float a, b, c,D;

	std::cin >> a >> b >> c;
	D = (b*b) - (4 * a*c);
	if (D >= 0)
	{
		std::cout << "The equation has real roots\n";
	}
	else
	{
		std::cout << "The equation has no answer\n";
	}


	return 0;
}