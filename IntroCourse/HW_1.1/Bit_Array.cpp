#include <iostream>

bool hasMoreOnes(unsigned int element)
{
	unsigned int mask = 1;
	unsigned int bit;

	unsigned int one = 1, zero = 0;
	unsigned int onesCounter = 0, zeroesCounter = 0;
	
	while (element)
	{
		bit = (element & mask);
		if (bit == one)
		{
			onesCounter++;
		}
		else if (bit == zero)
		{
			zeroesCounter++;
		}

		element >>= 1;
	}
	
	if (onesCounter > zeroesCounter)
	{
		return true;
	}

	return false;
}

unsigned int sumOfElements(unsigned int* numbers,unsigned int size)
{
	unsigned int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ( hasMoreOnes(numbers[i]) )
		{
			sum += numbers[i];
		}
	}

	return sum;
}

int main() {
	unsigned int size;
	std::cout << "Give the size of the array: \n";
	std::cin >> size;
	std::cout << "Fill array with numbers: \n";

	unsigned int* numbers = new unsigned int[size];
	for (int i = 0; i < size; i++)
	{
		std::cin >> numbers[i];
	}

	std::cout << "\nResult is: ";
	std::cout << sumOfElements(numbers, size) << "\n";

	delete[] numbers;
	return 0;
}