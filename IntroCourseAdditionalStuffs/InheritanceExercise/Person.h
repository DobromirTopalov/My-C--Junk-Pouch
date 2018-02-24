#pragma once
#include <iostream>

class Person {
private:
	char* name;
	int age;

public:

	Person();
	Person(char* name, int age);
	Person(const Person& obj);
	Person& operator=(const Person& obj);
	~Person();

	void setName(const char* name);
	char* getName();

	void setAge(int age);
	int getAge();

	friend std::ostream& operator<<(std::ostream& output,Person& obj);
};
