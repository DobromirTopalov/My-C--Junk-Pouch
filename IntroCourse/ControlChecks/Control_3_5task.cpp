#include <iostream>
#include <iomanip>

void draw(int n)
{
	int mid = 0 + (n - 0) / 2;
	if (n % 2 == 0)
	{
		for (int i = 1; i <= mid; i++)
		{
			std::cout << std::setw(mid+i-1);
			for (int j = i; j <= mid; j++)
			{
				std::cout << j;
			}
			std::cout<< "|\n";
		}
		for (int i = mid; i < n; i++)
		{
			std::cout <<std::setw(n)<< "|";
			int k = i + 2;
			for (int j = mid+1; j <k ; j++)
			{
				std::cout << j;
			}
			std::cout << "\n";

		}
	}
	else
	{
		for (int i = 1; i <= mid; i++)
		{
			std::cout << std::setw(mid + i + 1);
			for (int j = i; j <= mid+1; j++)
			{
				std::cout << j;
			}
			std::cout << "\n";
		}
		for (int i = mid; i < n; i++)
		{
			std::cout << std::setw(n) << "";
			int k = i + 2;
			for (int j = mid + 1; j <k; j++)
			{
				std::cout << j;
			}
			std::cout << "\n";

		}
	}
}

int main()
{
	int number;
	std::cin >> number;
	draw(number);

	return 0;
}