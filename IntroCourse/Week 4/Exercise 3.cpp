/*Зад.3
Напишете програма, която приема цяло положително число и намира броя на цифрите му.*/

#include <iostream>
#include <cmath>

int main()
{
	int number;
	std::cin >> number;

	if (number == 0)
	{
		std::cout << "1";
	}
	else
	{
		std::cout << (int)log10((double)abs(number)) + 1;
	}
	std::cout << "\n";


	return 0;
}