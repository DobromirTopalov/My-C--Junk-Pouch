/*Зад.5
Да се определи за дадено 6-цифрено число дали 3-цифреното число, 
образувано от първите 3 цифри на даденото, е по-малко от това, образурано от вторите 3.*/

#include <iostream>

int main()
{
	int number,fthree,sthree;
	std::cin >> number;
	
	fthree = number / 1000;
	sthree = number % 1000;

	if (fthree < sthree)
	{
		std::cout << "yes \n";
	}
	else if (fthree == sthree)
	{
		std::cout << "equal \n";
	}
	else
	{
		std::cout << "no \n";
	}

	return 0;
}