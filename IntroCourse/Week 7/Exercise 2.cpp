/*Зад.2
Да се състави програма на C++,чрез която се въвеждат символи до въвеждането на знака 'Z'. 
Програмата да изведе всички въведени символи в ред обратен на въвеждането им.*/

#include <iostream>

void symbols()
{
	char sign;
	std::cin >> sign;

	if (sign != 'Z')
	{
		symbols();
		std::cout << sign;
	}
	else
	{
		std::cout << "Z";
	}
}

int main()
{
	symbols();
	std::cout << "\n";

	return 0;
}