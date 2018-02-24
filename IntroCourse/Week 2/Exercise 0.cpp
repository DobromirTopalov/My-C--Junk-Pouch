/*Зад.18
Напишете програма, която приема символ и проверява дали е малка или главна латинска буква.*/

#include <iostream>

int main()
{
	char symbol;
	std::cin >> symbol;

	if (symbol >= 65 && symbol <= 90)
	{
		std::cout << "Upper-case latin letter! \n";
	}
	else if (symbol >= 97 && symbol <= 122)
	{
		std::cout << "Lower-case latin letter! \n";
	}
	else
	{
		;
	}

	return 0;
}