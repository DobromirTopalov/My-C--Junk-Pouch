#include "Person.h"
#include <cstring>

Person::Person()
{
	name = nullptr;
	age = 0;
}

Person::Person(char* name, int age):name(name)
{
	this->age = age;
}

Person::Person(const Person& obj)
{
	
	int size = strlen(obj.name);
	char* newname = new char[size+1];
	strcpy(newname, obj.name);
	this->name = newname;

	this->age = obj.age;

}

Person& Person::operator=(const Person& obj)
{
	if (this != &obj)
	{
		delete name;

		int size = strlen(obj.name);
		char* newname = new char[size+1];
		strcpy(newname, obj.name);
		this->name = newname;

		this->age = obj.age;
	}
	else
	{
		return *this;
	}
}

Person::~Person()
{
	;
}

void Person::setName(const char* name)
{
	strcpy(this->name, name);
}

char* Person::getName()
{
	return name;
}

void Person::setAge(int age)
{
	this->age = age;
}

int Person::getAge()
{
	return age;
}