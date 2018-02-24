#include <iostream>
#include <vector>

int main()
{
	std::vector <int>hui(5,'a');
	hui[2] = 9;

	std::cout <<hui[2]<< "\n";
	std::cout << hui[3] << "\n";

	std::vector <double>kor{ 1,4.5,8.9,32.2,6.6 };
	int index = 4;
	std::cout << kor[index]<<"\n";
	std::cout <<"``````````````````````````````````````````````````````````````````````````````````````" << "\n";

	int numbers;
	float avrg = 0.0f;

	std::cout <<"Enter how many numbers:"<< "\n";
	std::cin >> numbers;
	std::vector <int>values(numbers);
	
	for (int i = 0; i < numbers; i++)
	{
		std::cin >> values[i];
		avrg += values[i];

	}

	std::cout << "Your numbers are: \n";
	for (int j = 0; j < numbers-1; j++)
	{
		std::cout << values[j]<<",";
	}
	std::cout << values[numbers - 1]<<"\n";

	std::cout << "The avrg of numbers is: " << avrg/numbers << "\n";

	std::cout << "/////////////////////////////////////////";
	
	
	
	for (int kopche : values)
	{
		std::cout << "AZ SUM TOQ DETO ZNAE 2 i 200 \n";
	}
	
	
	
	return 0;
}