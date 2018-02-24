#pragma once
#include "Stringo.h"

class Brand
{
protected:
	Stringo name;
	int number;
public:
	Brand(Stringo name = "",int number=0)
	{
		this->name = name;
		this->number = number;
	}
	virtual ~Brand()
	{
		;
	}
	Brand(const Brand& obj)
	{
		this->name = obj.name;
		this->number = obj.number;
	}

	Brand& operator=(const Brand& obj)
	{
		this->name = obj.name;
		this->number = obj.number;

		return *this;
	}

	virtual std::ostream& operator<<(std::ostream& output) = 0;
	virtual std::istream& operator >> (std::istream& input) = 0;
	
	Stringo getName()
	{
		return name;
	}
	int getNumber()
	{
		return number;
	}

	std::istream& getline(std::istream& inFile, Stringo& buffer)
	{
		char temp;
		buffer = "";

		inFile.ignore(1);
		while (inFile.get(temp) && (temp != '\n'))
		{
			buffer.StringoCat(buffer, temp);
		}
		//std::cout << buffer << " | ";

		return inFile;
	}

};