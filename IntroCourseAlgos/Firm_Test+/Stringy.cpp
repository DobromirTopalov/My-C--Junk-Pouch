#include "Stringy.h"
#include <cstdlib>						//overloading new/delete - using malloc() and free() functions

Stringy::Stringy(char* buffer)
{
	this->buffer = buffer;
}

Stringy::~Stringy()
{
	;
}

Stringy::Stringy(const Stringy& obj)
{
	this->buffer = obj.buffer;
}

char Stringy:: operator[](int number) const
{
	return this->buffer[number];
}

void* Stringy:: operator new(size_t size)
{
	void* pointer;
	pointer = malloc(size);
	return pointer;
}

void Stringy:: operator delete(void* pointer)
{
	free(pointer);
}

Stringy& Stringy:: operator=(const Stringy& obj)
{
	int size = StringyLenght(obj.buffer);
	char* newbuffer = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newbuffer[i] = obj.buffer[i];
	}
	this->buffer = newbuffer;
	newbuffer = nullptr;
	return *this;
}

int Stringy::StringyLenght(const Stringy buffer) const
{
	int counter = 0;
	for (int i = 0; buffer[i] != '\0'; i++)
	{
		counter++;
	}
	return counter;
}

int Stringy::StringyCompare(const Stringy bufferOne,const Stringy bufferTwo) const
{
	int sizeOne = StringyLenght(bufferOne);
	int sizetwo = StringyLenght(bufferTwo);

	if (sizeOne < sizetwo)
	{
		return -1;
	}
	else if (sizeOne > sizetwo)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i <= sizeOne; i++)
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
		return 0;
	}
}

std::ostream& operator<<(std::ostream& out,const Stringy& obj)
{
	out << obj.buffer;
	return out;
}

std::istream& operator >> (std::istream& in, const Stringy& obj)
{
	in >> obj.buffer;
	return in;
}

Stringy& Stringy:: StringyCat(Stringy& bufferOne, const Stringy& bufferTwo)
{
	int sizeOne = StringyLenght(bufferOne);
	int sizeTwo = StringyLenght(bufferTwo);
	int fullsize = sizeOne + sizeTwo + 1;

	char* newstringy = new char[fullsize];
	for (int i = 0; i < sizeOne; i++)
	{
		newstringy[i] = bufferOne[i];
	}
	for (int i = sizeOne,p=0; i <fullsize; i++,p++)
	{
		newstringy[i] = bufferTwo[p];
	}
	bufferOne = newstringy;
	newstringy = nullptr;
	return bufferOne;
}

Stringy& Stringy::StringyCat(Stringy& bufferOne, const char temp)
{
	int sizeOne = StringyLenght(bufferOne);
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