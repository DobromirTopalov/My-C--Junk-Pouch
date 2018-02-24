/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <math.h>

int compare(int num1, int num2)
{
	int higherNum;
	if (num1 > num2)
	{
		higherNum = num1;
	}
	else if (num1 < num2)
	{
		higherNum = num2;
	}
	else if (num1 == num2)
	{
		higherNum = num1;
	}
	return higherNum;
}

int compare2(int num1, int num2)
{
	int	lowerNum;
	if (num1 > num2)
	{
		lowerNum=num2;
	}
	else if (num1 < num2)
	{
		lowerNum=num1;
	}
	else if (num1 == num2)
	{
		lowerNum=num2;
	}
	return lowerNum;
}

int loop(int number, int numberOne, int numberTwo)
{
	int lowerNum = compare2(numberOne, numberTwo);
	int digitL;
	int count = 0;

	while (lowerNum > 0)
	{
		digitL = lowerNum % 10;
		if (number == digitL)
		{
			count++;
		}
		
		lowerNum = lowerNum / 10;
	}
	return count;
}

void match(int numberOne, int numberTwo)
{
	int digitH, digitL;
	int higherNum = compare(numberOne, numberTwo);
	int lowerNum = compare2(numberOne, numberTwo);
	int count = 0;
	int countDigitH = 0;

	while (higherNum > 0)
	{
		digitH = higherNum % 10;
		countDigitH++;
		if (loop(digitH, numberOne, numberTwo) != 0)
		{
			count++;
		}

		higherNum = higherNum / 10;
	}

	if (count != countDigitH)
	{
		std::cout << "No \n";
	}
	else if (count == countDigitH)
	{
		std::cout << "Yes \n";
	}
}

int main()
{
	int firstNum, secondNum;
	std::cin >> firstNum >> secondNum;
	firstNum = abs(firstNum);
	secondNum = abs(secondNum);
	
	match(firstNum, secondNum);

	return 0;
}