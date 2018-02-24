#include <iostream>

void fillBuffer(int buffer[], int n = 0)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> buffer[i];
	}
	buffer[n] = '\0';
}

void printBuffer(int buffer[], int n)
{
	for (int j = 0; j < n-1; j++)
	{
		std::cout << buffer[j] << " , ";
	}
	std::cout << buffer[n - 1] << "\n";
}

void swaper(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sortWithBubble(int buffer[], int numberofelements)
{
	for (int k = 0; k < numberofelements - 1; k++)
	{
		for (int p = 0;  p< numberofelements - k - 1; p++)
		{
			if (buffer[p] > buffer[p + 1])
			{
				swaper(&buffer[p], &buffer[p + 1]);
			}
		}
	}
}

void sortWithSelection(int buffer[], int number)
{
	for (int i = 0; i < number; i++)
	{
		int index = i;
		for (int j = i; j < number-1; j++)
		{
			if (buffer[j] > buffer[j + 1])
			{
				index = j + 1;
			}
		}
		swaper(&buffer[i], &buffer[index]);
	}
}

bool binarySearch(int buffer[],int whattofind,int left,int right)
{
	while (!(left==right))
	{
		int mid = left + (right - left) / 2;
		
		if (buffer[mid] == whattofind)
		{
			return true;
		}
		else if (buffer[mid] > whattofind)
		{
			right = mid-1;
		}
		else
		{
			left = mid+1;
		}
	}
	return false;
}

bool recursivebinarySearch(int buffer[], int whattofind, int left, int right)
{
	if (!(left == right))
	{
		int mid = left + (right - left) / 2;

		if (buffer[mid] == whattofind)
		{
			return true;
		}
		else if (buffer[mid] > whattofind)
		{
			return recursivebinarySearch(buffer, whattofind, left, mid - 1);
		}
		else
		{
			return recursivebinarySearch(buffer, whattofind, mid + 1, right);
		}
	}
	return false;
}

int main()
{
	int* buffer = new int[10000];
	int numberofelements = 0;
	std::cout << "Enter numberofelements and a sequence: ";
	
	std::cin >> numberofelements;
	fillBuffer(buffer, numberofelements);
	
	sortWithBubble(buffer, numberofelements);
	printBuffer(buffer, numberofelements);
	std::cout << "__________________this is a sorted sequence.Enter a number to check if it is in the sequence: ";
	int numbertofind = 0;
	std::cin >> numbertofind;
	bool isHere = recursivebinarySearch(buffer, numbertofind, 0, numberofelements-1);

	if (isHere)
	{
		std::cout << "Number was found there!\n";
	}
	else
	{
		std::cout << "Number is missing there!\n";
	}

	return 0;
}