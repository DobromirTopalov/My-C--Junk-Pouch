#include <iostream>

int StringLength(char buffer[])
{
	int length = 0;
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		length++;
	}

	return length;
}

int StringCompare(char bufferOne[], char bufferTwo[])
{
	for (int i = 0; bufferOne[i] != '\0'; i++)
	{
		if (bufferOne[i] == bufferTwo[i])
		{
			continue;
		}
		else if (bufferOne[i] < bufferTwo[i])
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}


char* StringCopy(char** bufferOne, char bufferTwo[])
{
	int length = StringLength(bufferTwo);

	char* newbuffer = new char[length + 1];
	delete[] * bufferOne;

	for (int i = 0; i<length + 1; i++)
	{
		newbuffer[i] = bufferTwo[i];
	}
	*bufferOne = newbuffer;
	newbuffer = nullptr;

	return *bufferOne;
}

char* StringCat(char** bufferOne, char bufferTwo[])
{
	int length1 = StringLength(*bufferOne);
	int length2 = StringLength(bufferTwo);
	int fullSize = length1 + length2;

	char* newbuffer = new char[fullSize + 1];

	for (int i = 0; i < length1; i++)
	{
		newbuffer[i] = (*bufferOne)[i];
	}
	for (int i = length1; i <= fullSize; i++)
	{
		newbuffer[i] = bufferTwo[i - length1];
	}

	delete[] * bufferOne;
	*bufferOne = newbuffer;
	newbuffer = nullptr;

	return*bufferOne;

}

char* StringSubstring(char buffer[], int start, int end)
{
	int length = end - start;
	char* newbuffer = new char[length + 1];

	for (int i = start, k = 0; i <= end; i++, k++)
	{
		newbuffer[k] = buffer[i];
	}
	newbuffer[length + 1] = '\0';

	return newbuffer;
}

void printString(char buffer[])
{
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		std::cout << buffer[i];
	}
	std::cout << "\n";
}

int countWords(char buffer[])
{
	int counter = 0;
	bool isWord = false;
	int size = StringLength(buffer);

	for (int i = 0; buffer[i] != '\0'; i++)
	{
		if (((buffer[i] >= 'a') && (buffer[i] <= 'z')) || ((buffer[i] >= 'A') && (buffer[i] <= 'Z')))
		{
			isWord = true;
		}
		else
		{
			isWord = false;
		}

		if (isWord)
		{
			for (int j = i; j <=size; j++)
			{
				if (!((buffer[j] >= 'a') && (buffer[j] <= 'z')) && !((buffer[j] >= 'A') && (buffer[j] <= 'Z')))
				{
					isWord = false;
					i = j;
					counter++;
					break;
				}
			}
		}
	}
	return counter;
}

char** getWords(char buffer[],char ***tempBuffer)
{
	int counter = 0;
	int start = 0;
	int end = 0;
	bool isWord = false;
	int size = StringLength(buffer);

	for (int i = 0; buffer[i]!='\0'; i++)
	{
		if (((buffer[i] >= 'a') && (buffer[i] <= 'z')) || ((buffer[i] >= 'A') && (buffer[i] <= 'Z')))
		{
			isWord = true;
		}
		else
		{
			isWord = false;
		}

		if (isWord)
		{
			start = i;

			for (int j = i;j<=size; j++)
			{
				if (!((buffer[j] >= 'a') && (buffer[j] <= 'z')) && !((buffer[j] >= 'A') && (buffer[j] <= 'Z')))
				{
					isWord = false;
					end = j;
					i = j;
					int lenght = end - start;
					
					for (int k = start, n = 0; k <= end; k++, n++)
					{
						(*tempBuffer)[counter][n]=buffer[k];
					}
					(*tempBuffer)[counter][lenght] = '\0';
					
					counter++;
					break;
				}
			}
		}
	}

	return (*tempBuffer);
}

void swapper(char *&a, char *&b)
{
	char* temp = a;
	a = b;
	b = temp;
}

void sortText(char** buffer, int numberOfLines)
{
	for (int i = 0; i < numberOfLines-1; i++)
	{
		for (int j = 0; j < numberOfLines-i-1; j++)
		{
			if (StringCompare(*(buffer + j), *(buffer + j + 1)) == 1)
			{
				swapper(*(buffer + j), *(buffer + j + 1));
			}
		}
	}
}

void print2d(char** arr,int numberofwords)
{
	for (int i = 0; i < numberofwords; i++)
	{
		for (int j = 0; arr[i][j] != '\0'; j++)
		{
			std::cout<<arr[i][j];
		}
		std::cout << "\n";
	}
}

void print2d(char** arr, int numberofwords,char letter)
{
	for (int i = 0; i < numberofwords; i++)
	{
		if (arr[i][0] == letter)
		{
			for (int j = 0; arr[i][j] != '\0'; j++)
			{
				std::cout << arr[i][j];
			}
			std::cout << "\n";
		}
	}
}

void print2d(char** arr, int numberofwords, int length)
{
	for (int i = 0; i < numberofwords; i++)
	{
		int size = StringLength(*(arr + i));
		if (size == length)
		{
			for (int j = 0; arr[i][j] != '\0'; j++)
			{
				std::cout << arr[i][j];
			}
			std::cout << "\n";
		}
	}
}

void print2dToLength(char** arr, int numberofwords, int length)
{
	for (int i = 0; i < numberofwords; i++)
	{
		int size = StringLength(*(arr + i));
		if (size <= length)
		{
			for (int j = 0; arr[i][j] != '\0'; j++)
			{
				std::cout << arr[i][j];
			}
			std::cout << "\n";
		}
	}
}

int main()
{
	char* someString = new char[10000];
	//char* someOther = new char[10000];
	std::cin.getline(someString, 10000);
	
	int numberOfWords = countWords(someString);

	char** words = new char*[numberOfWords];
	for (int i = 0; i < numberOfWords; i++)
	{
		words[i] = new char[10000];
	}
	
	getWords(someString,&words);
	sortText(words, numberOfWords);
	print2d(words, numberOfWords);


	
	for (int i = 0; i < numberOfWords; i++)
	{
		delete[] words[i];
	}
	delete[] words;
	delete[] someString;

	return 0;
}