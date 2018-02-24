#include <iostream>
#include <vector>

#include <algorithm>

void print(const std::vector<int>& numbers);
/*
void permutation(std::vector<int>&numbers,int start,int end)
{
		if (start==end)
		{
			print(numbers);
			std::cout << "\n";
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				std::swap(numbers[start], numbers[i]);
				permutation(numbers, start+1, end);
				std::swap(numbers[start], numbers[i]);
			}
		}
}
*/
void print(const std::vector<int>& numbers)
{
	int size = numbers.size();
	std::cout << "{";
	for (int k = 0; k < size-1; k++)
	{
		std::cout << numbers[k] << " ";
	}
	std::cout << numbers[size-1] << "}\n";
}

int main()
{
	std::vector <int> numbers = {1,2,3,89,5,15,6,32};
	//permutation(numbers, 0, 5);
	//print(numbers);

	do {
		print(numbers);
		//std::cout << "\n";
	} while (next_permutation(begin(numbers), std::end(numbers)));

	return 0;
}