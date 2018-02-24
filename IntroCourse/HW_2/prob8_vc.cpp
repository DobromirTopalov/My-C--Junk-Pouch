/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 8
* @compiler VC
*
*/

#include <iostream>

int power(int a, int b = 1)
{
	int result = 1;
	for (int i = 1; i <= b; i++)
	{
		result = result*a;
	}
	return result;
}

int baseToDecimal(int numberToDecimal,int base)
{
	int digit;
	int result = 0;
	int k = 0;
	for (int i = 0; numberToDecimal > 0; i++)
	{
		digit = numberToDecimal % 10;
		result = result + digit*(power(base, k));
		k++;
		numberToDecimal = numberToDecimal / 10;
	}
	return result;
}

int sumOfDecimalNumbers(int firstDecimal, int secondDecimal)
{
	int sum;
	sum = firstDecimal + secondDecimal;
	return sum;
}

bool compare(int number,int base)
{
	bool match = false;
	int digit;
	for (int i = 0; number > 0; i++)
	{
		digit = number % 10;
		if (digit == base)
		{
			match = true;
		}
		number = number / 10;
	}
	return match;
}


int main()
{
	int numberOne, numberTwo,base;
	std::cin >> numberOne >> numberTwo>>base;

	if (compare(numberOne, base)==true || compare(numberTwo, base)==true)
	{
		std::cout << "Bad input data! \n";
	}
	else if (compare(numberOne, base) == false || compare(numberTwo, base) == false)
	{
		int copyOfNumberOne = sumOfDecimalNumbers(baseToDecimal(numberOne, base), baseToDecimal(numberTwo, base));

		///////////////////////////////////////////////////////////////////////////getting numbers

		int disorderedArr[] = { 0,0,0,0,0,0,0,0,0,0, };
		int result;
		for (int k = 0; copyOfNumberOne > 0; k++)
		{
			disorderedArr[k] = copyOfNumberOne%base;
			result = copyOfNumberOne / base;
			copyOfNumberOne = result;
		}

		///////////////////////////////////////////////////////////////////////////swap numbers
		int endResult = 0;
		int multiply = 1000000000;
		int ArrInOrder[] = { 0,0,0,0,0,0,0,0,0,0, };

		for (int i = 9; i >= 0; i--)
		{
			int k = 0;
			ArrInOrder[i] = disorderedArr[i];
			k++;
		}
		///////////////////////////////////////////////////////////////////////////forming number

		for (int j = 9; j >= 0; j--)
		{
			endResult = endResult + ArrInOrder[j] * multiply;
			multiply = multiply / 10;
		}

		///////////////////////////////////////////////////////////////////////////printing the result(formed number into base)
		if ((base >= 2 && base <= 10) && (numberOne >= 0 && numberOne <= 500000) && (numberTwo >= 0 && numberTwo <= 500000))
		{
			std::cout << endResult <<"\n";
		}
	}
	return 0;
}