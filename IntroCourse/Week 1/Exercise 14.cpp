/*Зад.14
Напишете програма, която проверява дали дадено четирицифрено число е палиндром.*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	int fDigit, sDigit, tDigit, foDigit;

	fDigit = number / 1000;
	sDigit = (number / 100) % 10;
	tDigit = (number / 10) % 10;
	foDigit = number % 10;
	
	if (fDigit == foDigit && sDigit == tDigit)
	{
		std::cout << "It is a Palindrome number.\n";
	}
	else
	{
		std::cout << "It is not a Palindrome number.\n";
	}

	return 0;
}