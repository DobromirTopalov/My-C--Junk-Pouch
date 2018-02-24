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
#include <math.h>

using namespace std;

int main() {
	int money;
	int moneyD50;
	int moneyD20;
	int moneyD10;
	int moneyD5;
	int moneyD2;
	int moneyD1;
	cin >> money;

	if (money > 0)
	{
		cout << money << "=";

		if (money / 50 > 0)
		{
			moneyD50 = money / 50;
			money = money - (moneyD50 * 50);
			cout << moneyD50 << "*50";
			if (money / 20 != 0 || money / 10 != 0 || money / 5 != 0 || money / 2 != 0 || money / 1 != 0)
			{
				cout << "+";
			}

		}
		else if (money / 50 == 0)
		{
			;
		}

		if (money / 20 > 0)
		{
			moneyD20 = money / 20;
			money = money - (moneyD20 * 20);
			cout << moneyD20 << "*20";
			if (money / 10 != 0 || money / 5 != 0 || money / 2 != 0 || money / 1 != 0)
			{
				cout << "+";
			}
		}
		else if (money / 20 == 0)
		{
			;
		}
		if (money / 10 > 0)
		{
			moneyD10 = money / 10;
			money = money - (moneyD10 * 10);
			cout << moneyD10 << "*10";
			if (money / 5 != 0 || money / 2 != 0 || money / 1 != 0)
			{
				cout << "+";
			}
		}
		else if (money / 10 == 0)
		{
			;
		}
		if (money / 5 > 0)
		{
			moneyD5 = money / 5;
			money = money - (moneyD5 * 5);
			cout << moneyD5 << "*5";
			if (money / 2 != 0 || money / 1 != 0)
			{
				cout << "+";
			}
		}
		else if (money / 5 == 0)
		{
			;
		}
		if (money / 2 > 0)
		{
			moneyD2 = money / 2;
			money = money - (moneyD2 * 2);
			cout << moneyD2 << "*2";
			if (money / 1 != 0)
			{
				cout << "+";
			}
		}
		else if (money / 2 == 0)
		{
			;
		}
		if (money / 1 > 0)
		{
			moneyD1 = money / 1;
			cout << moneyD1 << "*1";
		}
		else if (money / 1 == 0)
		{
			;
		}

		cout << "\n";
	}



	return 0;
}