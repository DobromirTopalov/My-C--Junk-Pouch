/*Зад.6
Да се състави програма на C++, която търси естествено число x, удовлетворяващо неравенството n^2 - (x^2 + 2*x + 1) <= 0.5 
Входни данни n - естествено число от интервала [10 .. 100].*/

#include <iostream>
#include <cmath>

int main()
{
	int n;
	bool isOkay = true;
	std::cin >> n;

	int i = 0;
	while (isOkay)
	{
		if ((double)(pow(n, 2) - (pow(i, 2) + 2 * i + 1)) <= 0.5)
		{
			std::cout << i;
			isOkay = false;
		}
		i++;
	}

	std::cout << "\n";

	return 0;
}