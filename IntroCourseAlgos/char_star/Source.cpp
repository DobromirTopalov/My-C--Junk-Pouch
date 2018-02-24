#include <iostream>
#include <cstring>

int sizeofStr(char* temparr)
{
	int elementNumber = 0;
	for (int i = 0; temparr[i] != '\0'; ++i)
	{
		elementNumber++;
	}

	return elementNumber;
}

char* copyofStr(char* temparrone, char* temparrtwo)
{
	int sizeOne = sizeofStr(temparrone);
	int sizeTwo = sizeofStr(temparrtwo);

	if (sizeOne != sizeTwo)
	{
		delete[] temparrone;
		char* newchar = new char[sizeTwo+1];
		for (int i = 0; i<=sizeTwo; ++i)
		{
			newchar[i] = temparrtwo[i];
		}
		temparrone = newchar;
		return temparrone;
	}
	else
	{
		for (int i = 0; i <= sizeTwo; ++i)
		{
			temparrone[i] = temparrtwo[i];
		}
		return temparrone;
	}
}

char* subStr(char* temparr,int leftIndex,int rightIndex)
{
	int sizeofBuffer = rightIndex - leftIndex;
	
	char* buffer = new char[sizeofBuffer+1];

	for (int i = 0; i <= sizeofBuffer; i++)
	{
		buffer[i] = temparr[leftIndex+i];
	}
	buffer[sizeofBuffer + 1] = '\0';
	return buffer;
}

int compareStr(char* temparrone, char* temparrtwo)
{
	
	for (int i = 0; temparrone[i] != '\0'; ++i)
	{
		if (temparrone[i] == temparrtwo[i])
		{
			continue;
		}
		else if (temparrone[i] < temparrtwo[i])
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

int main()
{
	char* tempOne = new char[1000];
	char* tempTwo = new char[1000];

	std::cin.getline(tempOne,10000);
	std::cin.getline(tempTwo, 10000);

	std::cout << compareStr(tempOne,tempTwo)<<" -this is custom version\n";
	std::cout << strcmp(tempOne, tempTwo) << " -this is strcmp version\n";
	return 0;
}