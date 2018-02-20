/*Зад.4
Напишете програма, която приема 3 реални числа - x, start и end и определя дали х лежи в интервала [start, end].*/

#include <iostream>

int main()
{
	float x, start, end;
	std::cin >> x >> start >> end;
	if (x >= start && x <= end)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}


	return 0;
}