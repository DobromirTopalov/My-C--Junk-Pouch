/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 2
* @compiler VC
*
*/

#include <iostream>

void prime(int num)
{
	if (num < 100000)
	{
			int count = 0;
			int count2 = 0;
			int count3 = 1;
			int p = 3;
			int q = 5;

		while (count3 <= num)
		{

			for (int a = 1; a <= p; a++)
			{
				if (p%a == 0)
				{
					count++;
				}
			}
			if (count == 2)
			{
				p = p;

				for (int a = 1; a <= q; a++)
				{
					if (q%a == 0)
					{
						count2++;
					}
				}
				if (count2 == 2)
				{
					q = p + 2;
					std::cout << p << " " << q << "\n";
					count3++;
				}
			}
			p++;
			q = p + 2;
			count = 0;
			count2 = 0;
		}
	}
}

int main()
{
	int n;
	std::cin >> n;
	prime(n);

	return 0;
}