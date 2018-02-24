/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3
* @compiler VC
*
*/

#include <iostream>

int tenthpower(int a, int b = 1)
{
	int result = 1;
	for (int i = 1; i <= b; i++)
	{
		result = result*a;
	}
	return result;
}

unsigned long int firstContains(unsigned long int numberOne, unsigned long int numberTwo)
{
	int digit;
	int digitcounter = 0;
	if (numberOne < 4000000000 && numberTwo < 4000000000)
	{
		for (int i = 1; numberOne > 0; i++)
		{
			digit = numberOne % 10;
			digitcounter++;
			numberOne = numberOne / 10;
		}
	}
	return digitcounter;
}

unsigned long int contains(unsigned long int numberOne, unsigned long int numberTwo)
{
	int counter = 0;
	int digit;
	int digitcounter = 0;

	if (numberOne < 4000000000 && numberTwo < 4000000000)
	{
		if (firstContains(numberOne, numberTwo) != 0)
		{
			for (int i = 1; numberTwo > 0; i++)
			{
				digit = numberTwo % (tenthpower(10, firstContains(numberOne, numberTwo)));
				if (digit == numberOne)
				{
					counter++;
				}
				numberTwo = numberTwo / 10;
			}
		}
	}
	return counter;
}


int main()
{

	unsigned long int a, b;
	std::cin >> a >> b;
	std::cout << contains(a, b);
	std::cout << "\n";

	return 0;
}