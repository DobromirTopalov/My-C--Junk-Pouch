#include <iostream>

void fillBuffer(int* buffer, int n)		//(int buffer[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(buffer + i);		//buffer[i]
	}
	*(buffer + n) = '\0';
}

void printBuffer(int* buffer, int n)						//(int buffer[],int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		std::cout << *(buffer + i) << " , ";			//buffer[i]
	}
	std::cout << *(buffer + (n - 1)) << "\n";			//buffer[n-1]
}

bool isHere(int buffer[], int numberofelements,int numbertofind)
{
	for (int i = 0; i < numberofelements; i++)
	{
		if (buffer[i] == numbertofind)
			return true;
	}
	return false;
}

int main()
{
	int* sequence = new int[10000];
	int numberofelements = 0;
	std::cout << "Enter a sequence and the number of elements in it: ";

	std::cin >> numberofelements;
	fillBuffer(sequence, numberofelements);

	std::cout << "Enter a number to search and find if any: ";
	int number;
	std::cin >> number;
	
	std::cout << "Your sequence is: ";
				printBuffer(sequence, numberofelements);
	std::cout<< "and you search for " << number << " in it!\n";

	std::cout << "-----------------------------------------------\n";
	if (isHere(sequence, numberofelements, number))
	{
		std::cout << "Your number found!\n";
	}
	else
	{
		std::cout << "Nothing found!\n";
	}


	return 0;
}