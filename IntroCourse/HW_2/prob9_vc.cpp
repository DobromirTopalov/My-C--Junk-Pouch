/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 9
* @compiler VC
*
*/

#include <iostream>

unsigned int totalDigitsOfFirstNumber(unsigned int number)
{
	unsigned int counter = 0;
	unsigned int digit;
	for (int i = 0; number > 0; i++)
	{
		digit = number % 10;
		number = number / 10;
		counter++;
	}
	return counter;
}

unsigned int formingNumber(int digit,int totalDigitsOfFirstNum,unsigned int masiv[])
{
	int multiply = 1;
	int result = 0;

	masiv[digit] = 0;
	for (int k = 0; k < totalDigitsOfFirstNum; k++)
	{
		if (masiv[k] != 0)
		{
			result = result + masiv[k] * multiply;
			multiply = multiply * 10;
		}
		else if (masiv[k] == 0)
		{
			continue;
		}
	}
	return result;
}

int main()
{
	unsigned int firstNumber,secondNumber;
	std::cin >> firstNumber >> secondNumber;
	unsigned int saveFirstNumber=firstNumber;

	bool match = false;

	unsigned int digitsOfFirstNumber[] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; firstNumber > 0; i++)
	{
		digitsOfFirstNumber[i] = firstNumber % 10;
		firstNumber = firstNumber / 10;
	}
	
	unsigned int copy[] = { 0,0,0,0,0,0,0,0,0,0 };

	for (int j = 0; j <totalDigitsOfFirstNumber(saveFirstNumber); j++)
	{
		
		for (int i = 0; i < 10; i++)
		{
			copy[i] = digitsOfFirstNumber[i];
		}

		if (formingNumber(j, totalDigitsOfFirstNumber(saveFirstNumber), copy)==secondNumber)
		{
			match = true; // okay
			break;
		}

	}

	if (match == true)
	{
		std::cout << "Yes \n";
	}
	else
	{
		std::cout << "No \n";
	}

	return 0;
}



