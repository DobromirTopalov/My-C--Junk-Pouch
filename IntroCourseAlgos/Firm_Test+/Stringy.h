#pragma once
#include <iostream>

class Stringy
{
protected:
	char* buffer;
public:
	Stringy(char* buffer=nullptr);
	~Stringy();
	Stringy(const Stringy& obj);
	Stringy& operator=(const Stringy& obj);

	int StringyLenght(const Stringy buffer) const;
	int StringyCompare(const Stringy bufferOne,const Stringy bufferTwo)const;
	Stringy& StringyCat(Stringy &bufferOne, const Stringy& bufferTwo);
	Stringy& StringyCat(Stringy &bufferOne, const char temp);
	char operator[](int number)const;

	void* operator new(size_t size);
	void operator delete(void* pointer);
	
	friend std::ostream& operator<<(std::ostream &out,const Stringy& obj);
	friend std::istream& operator>> (std::istream& in, const Stringy& obj);

	operator char()
	{
		char ch=buffer[0];
		return ch;
	}

};