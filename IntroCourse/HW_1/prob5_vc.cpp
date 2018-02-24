/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 5
* @compiler VC
*
*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	double x, y, u, v;
	cin >> x >> y >> u >> v;
	const int centerX = 0;
	const int centerY = 0;
	const int R1 = 8;
	const int R2 = 3;
	const int R3 = 1;
	double newX = x + u;
	double newY = y + v;
	double epsilon = 0.001;

	if (abs((newX*newX + newY*newY) - (R1*R1)) < epsilon || abs((newX*newX + newY*newY) - (R2*R2)) < epsilon || abs((newX*newX + newY*newY) - (R3*R3)) < epsilon)
	{
		cout << "0 \n";
	}

	else if ((sqrt(pow(newX - centerX, 2) + pow(newY - centerY, 2)))<R1 && (sqrt(pow(newX - centerX, 2) + pow(newY - centerY, 2)))>R2)
	{
		cout << "10 \n";
	}
	else if ((sqrt(pow(newX - centerX, 2) + pow(newY - centerY, 2)))>R3 && (sqrt(pow(newX - centerX, 2) + pow(newY - centerY, 2))) <R2)
	{
		cout << "20 \n";
	}
	else if ((sqrt(pow(newX - centerX, 2) + pow(newY - centerY, 2))) < R3)
	{
		cout << "60 \n";
	}

	else
	{
		cout << "0 \n";
	}

	return 0;
}