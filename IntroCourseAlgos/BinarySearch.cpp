#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>

int binarySearch(const std::vector<int>&array,int number)
{
	int size = array.size();
	int start = 0;
	int end = size - 1;
	int mid;

	while (start<=end)
	{
		mid = start + (end - start + 1) / 2;
		if (array[mid] == number)
		{
			return 1;
		}
		else if (number<array[mid])
		{
			end = mid-1;
		}
		else if (number>array[mid])
		{
			start = mid+1;
		}
	}
	return -1;
}

double time_execution(int(*search)(const std::vector<int>&, int),
	std::vector<int>& v, int trials) {
	int n = v.size();
	// Average the time over a specified number of trials
	double elapsed = 0.0;
	for (int iters = 0; iters < trials; iters++) {
		clock_t start_time = clock(); // Start the timer
		for (int i = 0; i < n; i++) // Search for all elements
			search(v, i);
		clock_t end_time = clock(); // Stop the timer
		elapsed += static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
	}
	return elapsed / trials; // Mean elapsed time per run
}

int main()
{
	std::cout << "---------------------------------------\n";
	std::cout << " Vector Linear Binary\n";
	std::cout << " Size Search Search\n";
	std::cout << "---------------------------------------\n";
	// Test the sorts on vectors with 1,000 elements up to
	// 10,000 elements.
	for (int size = 0; size < 50000; size += 5000)
	{
		std::vector<int>asd(size);
		for (int i = 0; i < size; i++)
			asd[i] = i;
		std::cout << std::setw(7) << size;

		std::cout << std::fixed << std::setprecision(3) << std::setw(12)
			<< time_execution(binarySearch, asd, 25)
			<< " sec\n";
	}
		
	return 0;
}