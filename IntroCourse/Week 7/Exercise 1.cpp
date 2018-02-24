/*Зад.1
Да се състави програма на C++, която изчислява произведение на две естествени числа =>2, като се използва само събиране.*/

#include <iostream>

int multiply(int a, int b)
{
	int result=b;
	if ((a == 0) || (b == 0))
	{
		return 0;
	}

	for (int i = 1; i < a; i++)
	{
		result += b;
	}
	return result;
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << multiply(a, b) << "\n";



	return 0;
}