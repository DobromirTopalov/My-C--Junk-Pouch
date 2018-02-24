/*Зад.8
Напишете програма която намира най-големия общ делител на две числа.*/

#include <iostream>

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b,a%b);	
	}
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	std::cout << GCD(a, b);


	return 0;
}