#include <iostream>
#include <vector>
#include <ctime>

const int MAX = 500000;
std::vector<bool> nonprimes(MAX);

int main() {
	nonprimes[0] = nonprimes[1] = true;

	for (int i = 2; i < MAX; i++) 
	{
		if (!nonprimes[i])
		{
			std::cout << i << " ";
			for (int j = 2 * i; j < MAX; j += i)
			{
				nonprimes[j] = true;
			}
		}
	}
	std::cout << '\n'; 
	
	return 0;
}