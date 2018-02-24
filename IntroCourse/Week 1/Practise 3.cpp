/*Зад.3
Да се определи дали цифрите на дадено трицифрено число са подредени във възходящ ред.*/

#include <iostream>

int main()
{
	int number, digitF, digitS, digitT;
	std::cin >> number;

	digitF = number / 100;
	digitS = ((number / 10) % 10);
	digitT = number % 10;

	if (digitT < digitS && digitS < digitF)
	{
		std::cout << "no \n";
	}
	else
	{
		std::cout << "yes \n";
	}


	return 0;
}