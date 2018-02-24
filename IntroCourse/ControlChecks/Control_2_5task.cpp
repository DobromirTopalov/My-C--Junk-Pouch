#include <iostream>
#include <iomanip>

void draw(int number)
{
	int mid = 0 + (number - 0) / 2;

	if (number % 2 == 0)
	{
		for (int k = 1; k <= mid; k++)
		{
			std::cout << std::setw(mid+k);
			for (int i = k; i <= number+1-k; i++)
			{
				std::cout<< i;
			}
			std::cout << "\n";
		}
		std::cout<<std::setw(mid*mid-1) << ".\n";
		int k = mid;
		while(k!=0)
		{
			std::cout << std::setw(mid + k);
			for (int i = k; i <= number+1-k; i++)
			{
				std::cout << i;
			}
			std::cout << "\n";
			k--;
		}
	}
	else
	{
		for (int k = 1; k <= mid; k++)
		{
			std::cout << std::setw(mid + k);
			for (int i = k; i <= number + 1 - k; i++)
			{
				std::cout << i;
			}
			std::cout << "\n";
		}
		
		int k = mid;
		while (k != 0)
		{
			std::cout << std::setw(mid + k);
			for (int i = k; i <= number + 1 - k; i++)
			{
				std::cout << i;
			}
			std::cout << "\n";
			k--;
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