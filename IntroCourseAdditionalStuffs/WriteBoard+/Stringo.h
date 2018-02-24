#pragma once
#include <iostream>

class Stringo
{
private:
	char* buffer;
public:
	Stringo(char* buffer = nullptr);
	~Stringo();
	Stringo(const Stringo& obj);
	Stringo& operator=(const Stringo& obj);

	int StringoLength(const Stringo& obj) const;
	Stringo& StringoCat(Stringo& bufferOne, const Stringo& bufferTwo);
	Stringo& StringoCat(Stringo& bufferOne, const char bufferTwo);
	int StringoCompare(const Stringo& bufferOne, const Stringo& bufferTwo);

	char operator [] (int number)const;

	friend std::ostream& operator<<(std::ostream& output, const Stringo& obj);
	friend std::istream& operator >> (std::istream& input, const Stringo& obj);

	void* operator new(size_t size);
	void operator delete(void* pointer);

};