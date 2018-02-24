#pragma once
#include "Person.h"
#include <iostream>

class Worker:public Person {
private:
	char* address;
	char* town;
	int yearsOfWorking;

public:

	Worker();
	Worker(char* nameOfPerson, int ageOfPerson,char* address, char* town, int ayearsOfWorking);
	Worker(const Worker& obj);
	Worker& operator=(const Worker& obj);
	~Worker();


	void setAddress(const char* address);
	char* getAddress();

	void setTown(const char* town);
	char* getTown();

	void setYearsOfWorking(int yearsOfWorking);
	int getYearsOfWorking();

	friend std::ostream& operator<<(std::ostream& output,Worker& obj);


};

