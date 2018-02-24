#include <iostream>
#include <iomanip>

void draw(int n)
{
	int k = 1;
	int i = 1;
	while (k <= n)
	{
		std::cout << std::setw(n-k);
		for (int j = 0; j < i; j++)
		{
			if (k <= n)
			{
				std::cout<<k<<" ";
				k++;
			}
		}
		std::cout << "\n";
		i++;
	}
}

int main()
{
	int n;
	std::cin>> n;

	draw(n);

	return 0;
}