/*Зад.1
Напишете програма, която приема три реални числа и ги извежда на екрана сортирани във възходящ(низходящ) ред.*/

#include <iostream>

int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;

	if ((a > b) && (b > c)&&(a>c))
	{
		std::cout << a<<b<<c<<"\n";
	}
	else if ((a > b) && (a>c)&&(b<c))
	{
		std::cout << a << c << b<<"\n";
	}
	else if ((a < b) && (b>c) && (a>c))
	{
		std::cout << b << a << c << "\n";
	}
	else if ((a < b) && (b>c) && (a<c))
	{
		std::cout << b << c << a << "\n";
	}
	else if ((c > a) && (b>a) && (b<c))
	{
		std::cout << c << b << a << "\n";
	}
	else
	{
		std::cout << c << a << b<<"\n";
	}


	return 0;
}