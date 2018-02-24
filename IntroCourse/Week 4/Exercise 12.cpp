/*Зад.12
Напишете програма, която проверява дали дадено число е автоморфно.*/

#include <iostream>
#include <cmath>

bool avto(int n)
{
	int number = pow(n, 2);
	int length = (int)log10((double)abs(n) + 1);
	length++;
	
	while (number)
	{
		if (number%(int)(pow(10,length)) == n)
		{
			return true;
		}
		else
		{
			number/=(int)(pow(10, length));
		}
	}

	return false;
}

int main()
{
	int a;
	std::cin >> a;
	std::cout << avto(a);

	//1, 5, 6, 25, 76, 376, 625, 9376 ... 

	return 0;
}