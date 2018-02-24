#pragma once
#include "Brand.h"

class Pencil :public Brand
{
private:
	Stringo category;
	int serialnumber;
public:
	Pencil(Stringo name = "", int number = 0, Stringo category = "", int serialnumber = 0):Brand(name,number)
	{
		this->category = category;
		this->serialnumber = serialnumber;
	}
	~Pencil()
	{
		;
	}
	Pencil(const Pencil& obj)
	{
		this->Brand::name = obj.name;
		this->Brand::number = obj.number;
		this->category = obj.category;
		this->serialnumber = obj.serialnumber;
	}

	Pencil& operator=(const Pencil& obj)
	{
		this->Brand::name = obj.name;
		this->Brand::number = obj.number;
		this->category = obj.category;
		this->serialnumber = obj.serialnumber;

		return *this;
	}

	std::ostream& operator<<(std::ostream& output)
	{
		//output << name << " " << number<<" " << category << " " << serialnumber;
		
		output << "Name of Person: " << name <<
			"\nAge: " << number <<
			"\nJob: " << category <<
			"\nPayday: " << serialnumber;
		return output;
	}
	std::istream& operator >> (std::istream& input)
	{
		getline(input, name);
		input >> number;
		getline(input, category);
		input >> serialnumber;

		//input >> name >> number >> category>>serialnumber;
		return input;
	}

	Stringo getCategory()
	{
		return category;
	}
	int getSerialNumber()
	{
		return serialnumber;
	}

};