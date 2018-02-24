#pragma once
#include "Brand.h"

class Marker:public Brand
{
private:
	Stringo color;
	int serialnumber;
public:
	Marker(Stringo name = "",int number=0,Stringo color ="", int serialnumber = 0):Brand(name,number)
	{
		this->color = color;
		this->serialnumber = serialnumber;
	}
	~Marker()
	{
		;
	}
	Marker(const Marker& obj)
	{
		this->Brand::name = obj.name;
		this->Brand::number = obj.number;
		this->color = obj.color;
		this->serialnumber = obj.serialnumber;
	}

	Marker& operator=(const Marker& obj)
	{
		this->Brand::name = obj.name;
		this->Brand::number = obj.number;
		this->color = obj.color;
		this->serialnumber = obj.serialnumber;

		return *this;
	}

	


	std::ostream& operator<<(std::ostream& output)
	{
		output << "Name of Person: "<<name <<
			"\nAge: " << number<<
			"\nJob: "<< color <<
			"\nPayday: "<<serialnumber;
		return output;
	}
	std::istream& operator >> (std::istream& input)
	{
		getline(input, name);
		input >> number;
		getline(input, color);
		input >> serialnumber;

		//input >> name >> number>> color >>serialnumber;
		return input;
	}

	Stringo getColor()
	{
		return color;
	}
	int getSerialNumber()
	{
		return serialnumber;
	}

};