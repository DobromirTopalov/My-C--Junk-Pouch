/*Зад.0
Напишете програма, която приема числа от клавиатурата, докато не срещне 0 и отпечатва сумата и произведението им.*/

#include <iostream>


int main()
{
	int sum = 0;
	int multiply = 1;

	bool enter = true;
	while (enter)
	{
		int number;
		std::cin >> number;

		if (number == 0)
		{
			enter = false;
			break;
		}
		else
		{			
			sum += number;
			multiply *= number;
		}
	}

	std::cout << sum << " and " << multiply << "\n";



	return 0;
}