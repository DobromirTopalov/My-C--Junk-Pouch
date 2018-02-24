/*Зад.14
Да се напише програма, която проверява дали дадено число е палиндром.*/

#include <iostream>
#include <cmath>

bool palindrom(int n)
{
	int size = (int)log10((double)abs(n) + 1) + 1;
	int end = size / 2;
	for (int i = 1,p=size-1; i <= end; i++)
	{
		int digit1 = n%(int)pow(10, 1);
		int digit2 = n / pow(10, p);
		if (digit1 != digit2)
		{
			return false;
		}
		
		n /= (int)pow(10, 1);
		p --;
		n %= (int)pow(10, p);
		p--;
	}
	return true;
}//7887

int main()
{
	int number;
	std::cin >> number;
	std::cout<<palindrom(number);

	return 0;
}