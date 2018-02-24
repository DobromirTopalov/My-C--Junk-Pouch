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
#include <math.h>

using namespace std;

int main() {

	int alphaX, alphaY, sideH, sideL;
	int betaX, betaY, sideH2, sideL2;

	cin >> alphaX >> alphaY >> sideH >> sideL;
	cin >> betaX >> betaY >> sideH2 >> sideL2;

	int area;

	if ((alphaX == betaX) && (alphaY == betaY) && (sideH == sideH2) && (sideL == sideL2))
	{
		area = sideH*sideL;
		cout << area << "\n";
	}
	else if (((alphaX + sideL) > (betaX + sideL2)) && ((betaY + sideH2) <(alphaY + sideH)))
	{
		area = (sideH2 * sideL2);
		cout << area << "\n";
	}
	else if (((alphaX + sideL) < (betaX + sideL2)) && ((betaY + sideH2) >(alphaY + sideH)))
	{
		area = (sideH * sideL);
		cout << area << "\n";
	}
	else if (alphaX >= (betaX + sideL2))
	{
		cout << "0 \n";
	}
	else if (betaY >= (alphaY + sideH))
	{
		cout << "0 \n";
	}
	else if ((alphaX < (betaX + sideL2)) && (betaY <(alphaY + sideH)))
	{
		area = ((betaX + sideL2) - alphaX)*((alphaY + sideH) - betaY);
		cout << area << "\n";
	}


	return 0;
}