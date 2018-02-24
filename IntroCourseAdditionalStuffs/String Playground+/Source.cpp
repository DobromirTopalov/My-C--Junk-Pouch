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

	for (int i = 0; i<length+1; i++)
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

	char* newbuffer = new char[fullSize+1];

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

	return* bufferOne;

}

char* StringSubstring(char buffer[], int start, int end)
{
	int length = end - start;
	char* newbuffer = new char[length + 1];

	for (int i=start,k=0; i <= end; i++,k++)
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

int main()
{
	char* someString=new char[10000];
	char* someOther = new char[10000];

	std::cin.getline(someString, 10000);
	std::cin.getline(someOther, 10000);

	std::cout << StringLength(someString)<<"\n";
	std::cout << StringLength(someOther) << "\n";

	std::cout << StringCompare(someString,someOther) << "\n";

	StringCat(&someString,someOther);
	printString(someString);

	StringCopy(&someString,someOther);
	printString(someString);
	printString(someOther);

	printString(StringSubstring(someString,2,5));



	return 0;
}