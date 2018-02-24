#include <iostream>
#include <cmath>

bool oneBit(unsigned int a, unsigned int b)
{
	unsigned int c = a^b;
	int i = 100;
	while (i >= 0)
	{
		if (c == pow(2, i))
		{
			return true;
		}
		i--;
	}
	return false;
}

int main()
{
	unsigned int a, b;
	std::cin >> a >> b;
	std::cout << std::boolalpha << oneBit(a, b)<<"\n";

	return 0;
}