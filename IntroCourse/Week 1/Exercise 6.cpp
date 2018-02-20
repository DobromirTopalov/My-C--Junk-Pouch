/* Зад.6
Да се напише булев израз, който проверява дали 3 числа могат да бъдат страни на триъгълник.*/

#include <iostream>

int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;

	if (a < (b + c) && b < (a + c) && c < (b + a))
	{
		std::cout << "yes\n";
	}
	else
	{
		std::cout << "no\n";
	}



	return 0;
}