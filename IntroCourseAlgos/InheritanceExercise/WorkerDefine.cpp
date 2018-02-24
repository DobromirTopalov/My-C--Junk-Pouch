#include "Worker.h"
#include <cstring>

Worker::Worker():Person()
{
	address = nullptr;
	town = nullptr;
	yearsOfWorking = 0;;
}

Worker::Worker(char* nameOfPerson, int ageOfPerson,char* address, char* town, int ayearsOfWorking) :address(address), town(town),Person(nameOfPerson,ageOfPerson)
{
	this->yearsOfWorking = ayearsOfWorking;
}

Worker::Worker(const Worker& obj):Person(obj)
{
	int sizeaddress = strlen(obj.address);
	char* newaddress = new char[sizeaddress+1];
	int sizetown = strlen(obj.town);
	char* newtown = new char[sizetown+1];

	strcpy(newaddress, obj.address);
	strcpy(newtown, obj.town);

	this->address = newaddress;
	this->town = newtown;
	this->yearsOfWorking = obj.yearsOfWorking;
}

Worker& Worker::operator=(const Worker& obj)
{
	if (this != &obj)
	{
		
		delete address;
		delete town;

		Person::operator=(obj);

		int sizeaddress = strlen(obj.address);
		char* newaddress = new char[sizeaddress + 1];
		int sizetown = strlen(obj.town);
		char* newtown = new char[sizetown + 1];

		strcpy(newaddress, obj.address);
		strcpy(newtown, obj.town);

		this->address = newaddress;
		this->town = newtown;
		this->yearsOfWorking = obj.yearsOfWorking;
	}
	else
	{
		return *this;
	}
}

Worker::~Worker()
{
	;
}

void Worker::setAddress(const char* address)
{
	strcpy(this->address, address);
}

char* Worker::getAddress()
{
	return address;
}

void Worker::setTown(const char* town)
{
	strcpy(this->town, town);
}

char* Worker::getTown()
{
	return town;
}

void Worker::setYearsOfWorking(int yearsOfWorking)
{
	this->yearsOfWorking = yearsOfWorking;
}

int Worker::getYearsOfWorking()
{
	return yearsOfWorking;
}
