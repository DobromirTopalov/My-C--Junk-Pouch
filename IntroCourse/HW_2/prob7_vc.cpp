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

int power(int a, int b = 1)
{
	int result = 1;
	for (int i = 1; i <= b; i++)
	{
		result = result*a;
	}
	return result;
}

void checkX(int num1, int num2, int num3)
{
	int oldX=1;
	int zero=0;
	for (int x = 1; x <= (num2 - 1); x++)
	{
		if (power(x, num1) % num2 == num3)
		{
			zero++;
			if (x > oldX)
			{
				std::cout << " ";
				std::cout << x;
			}
			if (x == oldX)
			{
				std::cout << x;
			}
			else if (x == (num2 - 1))
			{
				std::cout << "";
			}
			oldX = x;

		}
	}

		if(zero==0)
		{
			std::cout << "-1";
		}
}


int main()
{
	int n, m, y;
	std::cin >> n >> m >> y;
	if ((n > 0 && n < 1000001) && (m > 1 && m < 100001) && (y > 0 && y < m))
	{
		checkX(n,m,y);
		std::cout << "\n";

	}



	return 0;
}