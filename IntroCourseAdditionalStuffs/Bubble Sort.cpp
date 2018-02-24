#include <iostream>

void fillBuffer(int* buffer,int n)		//(int buffer[],int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(buffer+i);		//buffer[i]
	}
	*(buffer + n) = '\0';
}

void printBuffer(int* buffer,int n)						//(int buffer[],int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		std::cout << *(buffer + i) << " , ";			//buffer[i]
	}
	std::cout << *(buffer + (n - 1)) << "\n";			//buffer[n-1]
}
void swapElements(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortBuffer(int buffer[],int numberofelements)
{
	for (int i = 0; i < numberofelements - 1; i++)
	{
		for (int j = 0; j < numberofelements - 1 - i; j++)
		{
			if (buffer[j] > buffer[j + 1])
				swapElements(buffer[j], buffer[j + 1]);
		}
	}
}

int main() 
{
	int* sequence = new int[10000];
	std::cout << "Enter a sequence to sort and the number of elements in it: ";

	int numberofelements = 0;
	std::cin >> numberofelements;

	fillBuffer(sequence,numberofelements);
	printBuffer(sequence, numberofelements);

	std::cout << "---------------------------------\n";

	sortBuffer(sequence, numberofelements);
	printBuffer(sequence, numberofelements);



	return 0;
}