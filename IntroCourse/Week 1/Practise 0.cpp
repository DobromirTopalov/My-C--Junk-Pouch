/*Зад.0
Да се въведат две цели числа и да се опредили дали първото е делител на второто.*/

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	if (a%b == 0)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}

	return 0;
}