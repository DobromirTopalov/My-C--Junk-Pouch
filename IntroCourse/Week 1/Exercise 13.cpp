/*Зад.13
Напишете програма, която проверява дали цифрите на дадено трицифрено число образуват нарастваща(намаляваща) редица.*/

#include <iostream>

int main()
{
	int number,digitF,digitS,digitT;
	std::cin >> number;

	digitF = number / 100;
	digitS = ((number / 10) % 10);
	digitT = number % 10;

	if (digitT < digitS && digitS < digitF)
	{
		std::cout << "\/ \n";			//getting higher
	}
	else
	{
		std::cout << "\\ \n";			//getting lower
	}


	return 0;
}