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
#include <math.h>

using namespace std;

int main() {

	int firstNum, secondNum;
	char opeRator;
	cin >> firstNum >> opeRator >> secondNum;
	float result;

	//////////////////////////////////////////////////////////////////////////////////////////

	if ((firstNum >= 0) && (secondNum >= 0))
	{
		switch (secondNum % 16)
		{
		case 0: secondNum = 0; break;
		case 1: secondNum = 1; break;
		case 2: secondNum = 2; break;
		case 3: secondNum = 3; break;
		case 4: secondNum = 4; break;
		case 5: secondNum = 5; break;
		case 6: secondNum = 6; break;
		case 7: secondNum = 7; break;
		case 8: secondNum = 8; break;
		case 9: secondNum = 9; break;
		case 10: secondNum = 10; break;
		case 11: secondNum = 11; break;
		case 12: secondNum = 12; break;
		case 13: secondNum = 13; break;
		case 14: secondNum = 14; break;
		case 15: secondNum = 15; break;
		default: cout << "";
		}

		switch (firstNum % 16)
		{
		case 0: firstNum = 0; break;
		case 1: firstNum = 1; break;
		case 2: firstNum = 2; break;
		case 3: firstNum = 3; break;
		case 4: firstNum = 4; break;
		case 5: firstNum = 5; break;
		case 6: firstNum = 6; break;
		case 7: firstNum = 7; break;
		case 8: firstNum = 8; break;
		case 9: firstNum = 9; break;
		case 10: firstNum = 10; break;
		case 11: firstNum = 11; break;
		case 12: firstNum = 12; break;
		case 13: firstNum = 13; break;
		case 14: firstNum = 14; break;
		case 15: firstNum = 15; break;
		default: cout << "";
		}

		if (opeRator == '+')
		{
			result = (firstNum + secondNum);
		}
		if (opeRator == '-')
		{
			if (firstNum < secondNum)
			{
				result = (firstNum - secondNum);
				switch (16 - (int)result*-1)
				{
				case 0: result = 0;  cout << result; break;
				case 1: result = 1;  cout << result; break;
				case 2: result = 2;  cout << result; break;
				case 3: result = 3;  cout << result; break;
				case 4: result = 4;  cout << result; break;
				case 5: result = 5;  cout << result; break;
				case 6: result = 6;  cout << result; break;
				case 7: result = 7;  cout << result; break;
				case 8: result = 8;  cout << result; break;
				case 9: result = 9;  cout << result; break;
				case 10: result = 10;  cout << result; break;
				case 11: result = 11;  cout << result; break;
				case 12: result = 12;  cout << result; break;
				case 13: result = 13;  cout << result; break;
				case 14: result = 14;  cout << result; break;
				case 15: result = 15;  cout << result; break;
				default: cout << "";
				};
			}
			result = (firstNum - secondNum);
		}
		if (opeRator == '*')
		{
			result = (firstNum * secondNum);
		}

		if (opeRator == '/')
		{
			if (secondNum == 0)
			{
				cout << "Division by zero! \n";
				return 0;
			}
			result = (firstNum / secondNum);
		}
		if (opeRator == '%')
		{
			if (secondNum == 0)
			{
				cout << "Division by zero! \n";
				return 0;
			}
			result = (firstNum % secondNum);
		}

		switch ((int)result % 16)
		{
		case 0: result = 0;  cout << result; break;
		case 1: result = 1;  cout << result; break;
		case 2: result = 2;  cout << result; break;
		case 3: result = 3;  cout << result; break;
		case 4: result = 4;  cout << result; break;
		case 5: result = 5;  cout << result; break;
		case 6: result = 6;  cout << result; break;
		case 7: result = 7;  cout << result; break;
		case 8: result = 8;  cout << result; break;
		case 9: result = 9;  cout << result; break;
		case 10: result = 10;  cout << result; break;
		case 11: result = 11;  cout << result; break;
		case 12: result = 12;  cout << result; break;
		case 13: result = 13;  cout << result; break;
		case 14: result = 14;  cout << result; break;
		case 15: result = 15;  cout << result; break;
		default: cout << "";
		}
	}

	cout << "\n";
	return 0;
}