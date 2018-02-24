/*Зад.2
Едно число е Мерсеново, ако се представя във вида 2p - 1. Напишете пргорама, която приема цяло положително число n и намира 
всички Мерсенови числа по-малки от n.*/

#include <iostream>
#include <cmath>

int main()
{
	int number;
	std::cin >> number;
	bool isOkay = true;
	
	int i = 0;
	while(isOkay)
	{
		if ((pow(2, i) - 1) < number)
		{
			std::cout << pow(2, i) - 1 << " ";
			i++;
		}
		else
		{
			isOkay = false;
		}
	}
	std::cout << "\n";


	return 0;
}