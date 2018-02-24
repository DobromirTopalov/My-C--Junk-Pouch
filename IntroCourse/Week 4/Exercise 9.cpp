/*Зад.9
Напишете програма която намира най-малкото общо кратно на две числа.*/

#include <iostream>

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a%b);
	}
}

int LCM(int a, int b)
{
	return (a*b) / GCD(a, b);
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << LCM(a, b);

	return 0;
}