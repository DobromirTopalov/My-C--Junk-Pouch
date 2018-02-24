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

void printTextInCorrectFormat(const char* original, char** dublicate)
{
	unsigned int startIndex, endIndex;
	char* writePtr = *dublicate;
	
	for (unsigned int i = 0; original[i] != '\0'; ++i)
	{
		if ( (original[i] >= 'A' && original[i] <= 'Z') ||
			 (original[i] >= 'a' && original[i] <= 'z') ||
			 (original[i] >= '0' && original[i] <= '9') )
		{
			startIndex = i;
			unsigned int j;
			for (j = startIndex+1; original[j] != '\0'; ++j)
			{
				if ( !((original[j] >= 'A' && original[j] <= 'Z') ||
					  (original[j] >= 'a' && original[j] <= 'z')  ||
					  (original[j] >= '0' && original[j] <= '9')) )
				{
					break;
				}
			}
			
			endIndex = j;

			for (unsigned int p = endIndex - 1, k = startIndex; k < endIndex; --p, ++k)
			{
				*writePtr = original[p];
				++writePtr;
			}

			i = endIndex-1;
		}
		else
		{
			*writePtr = original[i];
			++writePtr;
		}
	}

	*writePtr = '\0';
}

void strcopy(char* dest, const char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		++src;
		++dest;
	}
	*dest = '\0';
}

int main()
{
	char* someText=new char[10000];
	char* outputText=new char[10000];
	
	std::cin.getline(someText, 10000);
	printTextInCorrectFormat(someText, &outputText);
	getText(outputText);
	
	delete[] outputText;
	delete[] someText;
	return 0;
}