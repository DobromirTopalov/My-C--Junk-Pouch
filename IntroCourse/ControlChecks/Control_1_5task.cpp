#include <iostream>
#include <iomanip>

void drawTree(int n)
{
	if (n % 2 == 0)
	{
		std::cout << "Happy new year!\n";
	}
	else
	{
		int mid = n / 2;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				std::cout << std::setw(n+2) << "+ \n";
			}
			if (i != 0 && i < n - 1)
			{
				std::cout<<std::setw(n-i)<< "o ";
				for (int j = 0; j < i; j++)
				{
					std::cout << "* ";
				}
				std::cout << "o\n";
			}
			if (i == n - 1)
			{
				std::cout << std::setw(n) << "|";
			}
		}
	}
}

int main()
{
	int number;
	std::cin >> number;

	std::cout << "\n";
	drawTree(number);
	std::cout << "\n";
	std::cout << "\n";
	return 0;
}