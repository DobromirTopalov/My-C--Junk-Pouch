/*Зад.11
Дадени са положителни, цели числа p и q. Напишете програма, която намира всички перфектни числа в интрвала [p, q].*/

#include <iostream>

void perfect(int p, int q)
{
	int sum = 1;
	for (int i = p; i <= q; i++)
	{
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0)
			{
				sum += j;
			}
		}

		if (sum == i)
		{
			std::cout << i<<" ";
		}
		sum = 1;
	}
}

int main()
{
	int p, q;
	std::cin >> p >> q;
	perfect(p, q);


	return 0;
}