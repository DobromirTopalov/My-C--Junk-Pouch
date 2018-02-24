/*Зад.2
Да се състави програма, която да изведе име на сезон по въведено естествено число от интервала [0..3].*/

#include <iostream>

int main()
{
	int month;
	std::cin >> month;

	if (month >= 0 && month <= 3)
	{
		switch (month)
		{

		case 0:	std::cout << "Spring!\n"; break;
		case 1:	std::cout << "Summer!\n"; break;
		case 2:	std::cout << "Autumn!\n"; break;
		case 3:	std::cout << "Winter!\n"; break;
		
		default: std::cout << "Anti-Conti\n"; break;

		}
	}
	else
	{
		std::cout << "Incorrect input!\n";
	}

	return 0;
}