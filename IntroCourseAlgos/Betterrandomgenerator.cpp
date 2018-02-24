#include <iostream>
#include <random>
#include <iomanip>

int randomnumber()
{
	int random_NUM;

	std::random_device seed;
	std::mt19937 random (seed());
	std::uniform_int_distribution<int> dist(1,100);
	
	random_NUM = dist(random);
	return random_NUM;
}

int main()
{
	char sign = 186;
	int number;
	std::cout << "How many random values you need : ";
	std::cin >> number;
	
	int counter = 1;
	while (counter <= number)
	{
		std::cout << "#"
			<< counter
			<< std::setw(4)
			<< randomnumber()
			<< "   out of "
			<< number
			<< " values "<<sign
			<<"\n";
		
		counter++;
	}

	std::cout << "\n";
	return 0;
}