#include <iostream>

bool oneBit(int a, int b)
{
	int c = a&b;
	if ((c==a)||(c==b))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << std::boolalpha << oneBit(a, b)<<"\n";

	return 0;
}