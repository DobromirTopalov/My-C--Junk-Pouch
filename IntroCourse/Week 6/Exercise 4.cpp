/*Зад.4
Да се напише булева функция, която проверява дали дадено естествено число е степен на 2.*/

#include <iostream>
#include <cmath>

bool isTwosPower(int n)
{
	for (int i = 0; i < 1000; i++)
	{
		if (n == (pow(2, i)))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int num;
	std::cin >> num;
	std::cout << std::boolalpha << isTwosPower(num) << "\n";

	return 0;
}