/*Зад.15
Напишете програма, която приема цяло число search и цифра digit и проверява дали digit е цифра на search.*/

#include <iostream>
#include <cmath>

bool tursq(int num, int b)
{
	int lenght = (int)log10((double)abs(num) + 1) + 1;
	while (num)
	{
		int digit = num % 10;
		if (digit == b)
		{
			return true;
		}
		num /= 10;
		
	}

	return false;
}


int main()
{
	int search, digit;
	std::cin >> search >> digit;
	std::cout<<tursq(search, digit)<<"\n";


	return 0;
}