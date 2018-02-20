/*Зад.3
Да се напише програма,в която потребителя въвежда 3 числа от клавиатурата и извежда средно аритметичното от сумата на тези, 
които са кратни на 2 и на 3.*/

#include <iostream>

int main()
{
	int one, two, three;
	std::cin >> one >> two >> three;
	int sumone, sumtwo, sumthree,sumtotal;
	int counter;

	if (one % 2 == 0 && one % 3 == 0)
	{
		sumone = one;
		counter = 1;
	}
	else
	{
		sumone = 0;
	}
	if (two % 2 == 0 && two % 3 == 0)
	{
		sumtwo = two;
		counter = 2;
	}
	else
	{
		sumtwo = 0;
	}
	if (three % 2 == 0 && three % 3 == 0)
	{
		sumthree = three;
		counter = 3;
	}
	else
	{
		sumthree = 0;
	}

	sumtotal = (sumone + sumtwo + sumthree) / counter;
	std::cout <<"\n"<< sumtotal << "\n";


	return 0;
}