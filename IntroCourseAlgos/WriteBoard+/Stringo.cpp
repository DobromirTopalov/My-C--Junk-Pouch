#include "Stringo.h"
#include <cstdlib>

Stringo::Stringo(char* buffer)
{
	this->buffer = buffer;
}

Stringo::~Stringo()
{
	;
}

Stringo::Stringo(const Stringo& obj)
{
	this->buffer = obj.buffer;
}

Stringo& Stringo::operator=(const Stringo& obj)
{
	int length = obj.StringoLength(obj);
	char* newbuffer = new char[length + 1];
	for (int i = 0; i <= length; i++)
	{
		newbuffer[i] = obj.buffer[i];
	}

	this->buffer = newbuffer;
	newbuffer = nullptr;

	return *this;
}

int Stringo:: StringoLength(const Stringo& obj)const
{
	int size = 0;
	for (int i = 0; obj.buffer[i] != '\0'; i++)
	{
		size++;
	}
	return size;
}

Stringo& Stringo::StringoCat(Stringo& bufferOne, const Stringo& bufferTwo)
{
	int sizeOne = bufferOne.StringoLength(bufferOne);
	int sizeTwo = bufferTwo.StringoLength(bufferTwo);
	int fullSize = sizeOne + sizeTwo + 1;
	char* newbuffer = new char[fullSize];
	
	for (int i = 0; i < sizeOne; i++)
	{
		newbuffer[i] = bufferOne[i];
	}
	for (int i = sizeOne,p=0; i < fullSize; i++,p++)
	{
		newbuffer[i] = bufferTwo[p];
	}

	bufferOne.buffer = newbuffer;
	newbuffer = nullptr;

	return bufferOne;
}

Stringo& Stringo::StringoCat(Stringo& bufferOne, const char temp)
{
	int sizeOne = bufferOne.StringoLength(bufferOne);
	int sizeTwo = 1;
	int fullSize = sizeOne + sizeTwo;
	char* newbuffer = new char[fullSize];

	for (int i = 0; i < sizeOne; i++)
	{
		newbuffer[i] = bufferOne[i];
	}
	for (int i = sizeOne; i < fullSize; i++)
	{
		newbuffer[i] = temp;
	}
	newbuffer[fullSize] = '\0';
	bufferOne.buffer = newbuffer;
	newbuffer = nullptr;

	return bufferOne;
}

int Stringo:: StringoCompare(const Stringo& bufferOne, const Stringo& bufferTwo)
{
	int sizeOne = bufferOne.StringoLength(bufferOne);
	int sizeTwo = bufferTwo.StringoLength(bufferTwo);
	
	if (sizeOne < sizeTwo)
	{
		return -1;
	}
	else if (sizeOne > sizeTwo)
	{
		return 1;
	}
	else
	{
		for (int i = 0; bufferOne[i] != '\0'; i++)
		{
			if (bufferOne[i] < bufferTwo[i])
			{
				return -1;
			}
			else if (bufferOne[i] > bufferTwo[i])
			{
				return 1;
			}

		}
	}
	return 0;
}

std::ostream& operator<<(std::ostream& output, const Stringo& obj)
{
	output << obj.buffer;
	return output;
}

std::istream& operator >> (std::istream& input, const Stringo& obj)
{
	input >> obj.buffer;
	return input;
}

char Stringo:: operator [] (int number)const
{
	return this->buffer[number];
}

void* Stringo::operator new(size_t size)
{
	void* pointer=malloc(size);
	return pointer;
}

void Stringo:: operator delete(void* pointer)
{
	free(pointer);
}