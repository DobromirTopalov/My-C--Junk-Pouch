/*Зад.16
Напишете програма, която приема две цели числа search и find и проверява дали find се съдържа във search.*/

#include <iostream>
#include <cmath>

bool tursq(int num, int b)
{
	int lenght = (int)log10((double)abs(num) + 1) + 1;
	int len = (int)log10((double)abs(b) + 1) + 1;

	while (num)
	{
		int digit = num % (int)pow(10,len);
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
	std::cout << tursq(search, digit) << "\n";


	return 0;
}