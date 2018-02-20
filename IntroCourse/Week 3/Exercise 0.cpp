/*«ад.0
Ќапишете програма, ко€то приема две цели числа и извежда по-гол€мото(по-малкото) от двете.*/

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a>> b;

	if (a >= b)
	{
		std::cout << a;
	}
	else
	{
		std::cout << b;
	}
	std::cout << "\n";

	return 0;
}