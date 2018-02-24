#include <iostream>  
#include <cmath>

bool allBits(int a)
{
	int c = (a >> 1);
	if (((a >> 1) == c) || ((c >> 1) == a))
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
	int a;
	std::cin >> a;
	std::cout<<std::boolalpha<<allBits(a)<<"\n";

	return 0;
}