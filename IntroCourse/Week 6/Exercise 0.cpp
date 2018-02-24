/*Зад.0
Да се напише функция, която приема един параметър от тип int и връща числото увеличено с 1.*/

#include <iostream>

int increase(int n)
{
	return ++n;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << increase(n) << "\n";


	return 0;
}