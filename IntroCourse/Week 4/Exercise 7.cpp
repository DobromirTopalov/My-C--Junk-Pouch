/*Зад.7
Напишете програма, която по въведени от клавиатурата цели числа x и n и цифра digit заменя n-тата цифра(броейки отзад-напред!) 
на x с digit.*/

#include <iostream>
#include <cmath>

int main()
{
	int x, n, digit;
	std::cin >> x >> n >> digit;

	int cock = 1;
	int tail = 1;
	
	if ((n > 0) && (digit >= 0 && digit <= 9))
	{

		switch (n - 1)
		{
		case 0:	cock = x / 10; tail = x % 10; break;
		case 1: cock = x / 10; tail = x % 10; break;
		case 2: cock = x / 100; tail = x % 100; break;
		case 3: cock = x / 1000; tail = x % 1000; break;
		case 4: cock = x / 10000; tail = x % 10000; break;
		case 5: cock = x / 100000; tail = x % 100000; break;
		case 6: cock = x / 1000000; tail = x % 1000000; break;
		case 7: cock = x / 10000000; tail = x % 10000000; break;
		case 8: cock = x / 100000000; tail = x % 100000000; break;
		default: break;

		}

		if ((n-1) > 0)
		{
			cock /= 10;
			cock *= 10;
			cock += digit;
			cock *= pow(10, n-1);
			x = cock + tail;
		}
		else if ((n - 1) == 0)
		{
			cock *= 10;
			cock += digit;
			x = cock;
		}

		std::cout << x << "\n";
	}
	else
	{
		std::cout << "Wrong case!\n";
	}
 
	return 0;
}