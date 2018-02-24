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
#include <iomanip>
#include <cmath>

void fillnumberOfN(double numberOfN[], int &N)
{
	for (int i = 0; i < N; i++)
	{
		std::cin >> numberOfN[i];
	}
}

double speed(int n, double interval, double acc[])
{
	double speed = 0;
	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			speed = speed + acc[i] * interval;
			if (speed <= 0)
			{
				speed = 0;
			}
			else if (speed > 0)
			{
				speed = abs(speed);
			}
		}
	}
	return speed;
}

double distance2(int n, double interval, double acc[])
{
	double distance = 0;
	distance = speed(n - 1, interval, acc)*interval + ((0.5) * (acc[n - 1] * pow(interval, 2)));
	if (distance <= 0)
	{
		distance = 0;
	}
	else if (distance > 0)
	{
		distance = abs(distance);
	}
	return distance;
}

double totalDistance(int n, double interval, double acc[])
{
	double distance = 0;
	for (int i = 0; i < n; i++)
	{
		distance = distance + distance2(n - i, interval, acc);
	}
	return distance;
}

int main()
{
	int N;
	double D;
	std::cin >> N >> D;

	double numberOfN[100000];
	fillnumberOfN(numberOfN, N);

	std::cout << std::fixed;
	std::cout << std::setprecision(5) << totalDistance(N, D, numberOfN) << "\n";

	return 0;
}