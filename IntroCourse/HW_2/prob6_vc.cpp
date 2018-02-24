/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 6
* @compiler VC
*
*/

#include <iostream>

unsigned long int factorial(unsigned long int number);
unsigned long int binomialCoef(unsigned long int numN, unsigned long int numK);

unsigned long int factorial(unsigned long int number)
{
	unsigned long int result=1;
	for (unsigned long int i = 0; i < number; i++)
	{
		result = result*(number - i);
	}

	return result;
}


unsigned long int binomialCoef(unsigned long int numN, unsigned long int numK)
{
	unsigned long int coef;
	coef = factorial(numN) / (factorial(numK)*factorial((numN - numK)));

	return coef;
}

void printAllBinomialCoef(unsigned long int numberN, unsigned long int numberK = 0)
{
	for (numberK = 0; numberK <= numberN; numberK++)
	{
		std::cout << binomialCoef(numberN, numberK);
		if (numberK < numberN)
		{
			std::cout << " ";
		}
		else if (numberK == numberN)
		{
			std::cout << "";
		}
	}
}

int main()
{
	unsigned long int n;
	std::cin >> n;
	printAllBinomialCoef(n);
	std::cout << "\n";
	

	return 0;
}