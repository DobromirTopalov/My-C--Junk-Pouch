#include <iostream>
#include <cstring>

void getText(const char* text)
{
	unsigned int size = strlen(text);
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << text[i];
	}
	std::cout << "\n";
}

void swap(char &one, char &two)
{
	char temp = one;
	one = two;
	two = temp;
}

void printTextInCorrectFormat(char** original)
{
	unsigned int startIndex, endIndex;

	for (unsigned int i = 0; (*original)[i] != '\0'; ++i)
	{
		if (( (*original)[i] >= 'A' && (*original)[i] <= 'Z') ||
			( (*original)[i] >= 'a' && (*original)[i] <= 'z') ||
			( (*original)[i] >= '0' && (*original)[i] <= '9'))
		{
			startIndex = i;

			for (unsigned int j = startIndex + 1; (*original)[j] != '\0'; ++j)
			{
				if (!(  ( (*original)[j] >= 'A' && (*original)[j] <= 'Z') ||
					   ( (*original)[j] >= 'a' && (*original)[j] <= 'z') ||
					   ( (*original)[j] >= '0' && (*original)[j] <= '9') ))
				{
					endIndex = j-1;
					break;
				}
				else
				{
					endIndex = j;
				}

			}

			for (unsigned int p = startIndex, k = endIndex; p < k; p++, k--)
			{
				swap((*original)[p], (*original)[k]);
			}

			i = endIndex+1;
		}
		
	}
}

int main()
{
	char* someText = new char[10000];
	std::cin.getline(someText, 10000);

	printTextInCorrectFormat(&someText);
	getText(someText);

	delete[] someText;

	return 0;
}