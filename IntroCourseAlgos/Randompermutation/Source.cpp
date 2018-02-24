#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

void print(const std::vector<int>& numbers);
int random(int start, int end);

void permutation(std::vector<int>&numbers)
{
	int size = numbers.size();
	for (int i = 0; i < size - 1; i++)
		std::swap(numbers[i], numbers[random(i, size)]);
}


void print(const std::vector<int>& numbers)
{
	int size = numbers.size();
	std::cout << "{";
	for (int k = 0; k < size - 1; k++)
	{
		std::cout << numbers[k] << " ";
	}
	std::cout << numbers[size - 1] << "}\n";
}

int random(int start, int end)
{
	if (start >= end)
	{
		return 0;
	}
	else
	{
		int range = end - start;
		return rand() % range + start;
	}
}

int main()
{
	std::vector <int> numbers = {36,8,-9,0,1,7,14};
	srand (static_cast<int>(time(0)));

	print(numbers);
	std::cout << '\n';

	///////////////////////////////////////////////////////

	int j = 1;
	while (j < 3000000) {
		permutation(numbers);
		std::cout << "# " << j << " : ";
		print(numbers);
		j++;
	}

	return 0;
}