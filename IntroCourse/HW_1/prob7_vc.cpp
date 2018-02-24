/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 7
* @compiler VC
*
*/

#include <iostream>
#include <math.h>

using namespace std;

int main() {

	int bigCircleX = 0;
	int bigCircleY = 0;
	int smallBlackX = 0;
	int smallBlackY = 3;
	int smallWhiteX = 0;
	int smallWhiteY = -3;
	const int bigRad = 6;
	const int smallBlackRad = 1;
	const int smallWhiteRad = 1;
	const int mediumBwRad = 3;
	const int mediumWbRad = 3;

	double x, y;
	cin >> x >> y;

	if ((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) < smallBlackRad)
	{
		cout << "Evil";
	}
	if ((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) == smallBlackRad)
	{
		cout << "Neutral";
	}
	if (((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) > smallBlackRad) && ((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) < mediumBwRad) && (x >= 0 && x <= 6 && y > 0 && y < 6))
	{
		cout << "Good";
	}
	if (((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) > smallBlackRad) && ((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) == mediumBwRad) && (x >= 0 && x <= 6 && y > 0 && y < 6))
	{
		cout << "Neutral";
	}
	if (((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) > smallBlackRad) && ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) < bigRad) && (x <= 0 && x >= -6 && y > 0 && y <= 6))
	{
		cout << "Good";
	}
	if (((sqrt(pow(smallBlackX - x, 2) + pow(smallBlackY - y, 2))) > mediumBwRad) && ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) < bigRad) && (x >= 0 && x <= 6 && y >= 0 && y <= 6))
	{
		cout << "Evil";
	}
	if ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) >= bigRad && ((x >= -6 && x <= 6 && y >= 0 && y <= 6)))
	{
		cout << "Neutral";
	}

	/////////////////////////////////////////////////////mahnah nulite na neutral good neutral evil 3ti 4ti pred ycite

	if ((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) < smallWhiteRad)
	{
		cout << "Good";
	}
	if ((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) == smallWhiteRad)
	{
		cout << "Neutral";
	}
	if (((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) > smallWhiteRad) && ((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) < mediumWbRad) && (x <= 0 && x >= -6 && y < 0 && y > -6))
	{
		cout << "Evil";
	}
	if (((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) > smallWhiteRad) && ((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) == mediumWbRad) && (x <= 0 && x >= -6 && y < 0 && y > -6))
	{
		cout << "Neutral";
	}
	if (((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) > smallWhiteRad) && ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) < bigRad) && (x >= 0 && x <= 6 && y < 0 && y >= -6))
	{
		cout << "Evil";
	}
	if (((sqrt(pow(smallWhiteX - x, 2) + pow(smallWhiteY - y, 2))) > mediumWbRad) && ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) < bigRad) && (x <= 0 && x >= -6 && y <= 0 && y >= -6))
	{
		cout << "Good";
	}
	if ((sqrt(pow(bigCircleX - x, 2) + pow(bigCircleY - y, 2))) >= bigRad && ((x >= -6 && x <= 6 && y <= 0 && y >= -6)))
	{
		cout << "Neutral";
	}
	if (x == 0 && y == 0)
	{
		cout << "Neutral";
	}

	cout << "\n";





	return 0;
}