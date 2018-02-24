#include "Dynamic.h"

Dynamic::Dynamic()						
{
	memoryBox = nullptr;
	size = 0;
	capacity = changeCap();
}


Dynamic::Dynamic(const char* string)
{
	int length = strlen(string);
	memoryBox = new char[length + 1];

	strcpy(memoryBox, string);
	size = length;
	capacity = changeCap();
}


Dynamic::Dynamic(const Dynamic& obj)
{
	int length = strlen(obj.memoryBox);
	memoryBox = new char[length +1];

	strcpy(memoryBox,obj.memoryBox);
	size = obj.size;
	capacity = obj.capacity;
}


Dynamic& Dynamic::operator=(const Dynamic& obj)					//asdasdasdasdasdasd  
{
	if (this != &obj)
	{
		delete memoryBox;
		int length = strlen(obj.memoryBox);

		char* newmemoryBox = new char[length + 1];
		strcpy(newmemoryBox, obj.memoryBox);
		memoryBox = newmemoryBox;
		size = obj.size;
		capacity = obj.capacity;
	}
	//else {													//tuk sus ili bez else bi sledvalo da e?
		return *this;											
	//}
}


Dynamic Dynamic::operator+(const Dynamic& obj)
{
	Dynamic temporary=*this;
	int length = strlen(temporary.memoryBox) + strlen(obj.memoryBox);
	char* temp = new char[length+1];
	
	strcpy(temp, temporary.memoryBox);
	strcat(temp, obj.memoryBox);
	
	delete temporary.memoryBox;
	temporary.memoryBox = temp;
	temporary.size += obj.size;
	temporary.capacity += obj.capacity;
	
	return temporary;
}


char Dynamic::operator[](int a)
{
	return memoryBox[a];
}


Dynamic::~Dynamic()
{
	delete memoryBox;
}


char*Dynamic::getBox()
{
	return memoryBox;
}


int Dynamic::getSize()
{
	return size;
}


void Dynamic::add(const char* neshto)
{
	if (size + strlen(neshto) <= capacity)
	{
		capacity = (size + strlen(neshto))*2;
		size = (size + strlen(neshto));
		char* newBox = new char[capacity];

		strcpy(newBox, memoryBox);
		strcat(newBox, neshto);
		delete memoryBox;
		memoryBox = newBox;
	}
	else
	{
		capacity = (size + strlen(neshto));
		char* newBox = new char[capacity];

		strcpy(newBox, memoryBox);
		strcat(newBox, neshto);

		delete memoryBox;
		memoryBox = newBox;
		size = strlen(memoryBox);
		capacity = (size + strlen(neshto)) * 2;
	}
}


void Dynamic::del(int value)
{
	int length = strlen(memoryBox);

	for (int i = 1; i <= value; i++)
	{
		memoryBox[length -i] = '\0';
	}
	size = length - value;
}


void Dynamic::clear()
{
	delete memoryBox;
	memoryBox = nullptr;
	size = 0;
	capacity = changeCap();
}


void Dynamic::insert(const char* neshto,int a)
{

	if (a == 0)
	{
		int sizer = strlen(neshto) + strlen(memoryBox);
		char* buffer = new char[sizer+1];

		strcpy(buffer, neshto);
		strcat(buffer, memoryBox);

		delete memoryBox;
		memoryBox = buffer;
		size = strlen(memoryBox);
		capacity = (strlen(memoryBox) * 2);
	}
	else if (a == strlen(memoryBox)+1)
	{
		int siz = strlen(memoryBox) + strlen(neshto);
		char* buff = new char[siz + 1];

		strcpy(buff, memoryBox);
		strcat(buff, neshto);

		delete memoryBox;
		memoryBox = buff;
		size = strlen(memoryBox);
		capacity = (strlen(memoryBox) * 2);
	}
	else
	{
		int length = strlen(memoryBox) + 1;
		int lengthofneshtoto = strlen(neshto) + 1;

		char* tempone = new char[a + 2];
		char* temptwo = new char[length - a];
		char* tempfull = new char[lengthofneshtoto + length];

		for (int i = 0; i <= a; i++)
		{
			tempone[i] = memoryBox[i];
		}
		tempone[a + 1] = '\0';
			strcpy(tempfull, tempone);
			delete[] tempone;

		for (int i = a + 1, k = 0; i < length; i++, k++)
		{
			temptwo[k] = memoryBox[i];
		}

		strcat(tempfull, neshto);
		strcat(tempfull, temptwo);
			delete[] temptwo;

		delete memoryBox;
		memoryBox = tempfull;
		size = strlen(memoryBox);
		capacity = (strlen(memoryBox) * 2);
	}
}


int Dynamic::length()
{
	if (memoryBox != nullptr)
		return strlen(memoryBox);
	else
		return 0;
}


bool Dynamic::isEmpty()
{
	if (memoryBox != nullptr)
		return (strlen(memoryBox) != 0) ? false : true;
	else
		return true;
}


int Dynamic::changeCap()
{
	capacity = size*2;
	return capacity;
}