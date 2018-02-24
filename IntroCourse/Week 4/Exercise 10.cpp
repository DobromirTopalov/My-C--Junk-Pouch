/*Зад.10
Напишете програма която приема число n, и отпечтва n-тото число на Фибоначи.*/

#include <iostream>

int fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return fibo(n-2) + fibo(n - 1);
	}
}

int main()
{
	int a, b;
	std::cin >> a;

	std::cout << fibo(a);

	return 0;
}