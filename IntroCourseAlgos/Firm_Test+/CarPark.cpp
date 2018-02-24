#include "CarPark.h"

CarPark::CarPark(Stringy nameOne, Stringy nameTwo, Stringy startDate, Stringy endDate, float price, Stringy content, Stringy category, unsigned int number)
	:Project(nameOne, nameTwo, startDate, endDate, price, content)
{
	this->number = number;
	this->category = category;
}

CarPark::~CarPark()
{
	;
}

CarPark::CarPark(const CarPark& obj)
{
	this->number = obj.number;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;


	this->Firm::name = obj.Firm::name;

}

CarPark& CarPark:: operator=(const CarPark& obj)
{
	this->number = obj.number;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;

	this->Firm::name = obj.Firm::name;


	return *this;
}

Stringy CarPark::addContent(char* buffer)
{
	Stringy temp = (buffer);
	this->content = temp.StringyCat(content, temp);
	return content;
}

Stringy CarPark:: getCategory()
{
	return category;
}
unsigned int CarPark ::getNumber()
{
	return number;
}


std::ostream& operator<<(std::ostream& out, const CarPark& obj)
{
	out << "\tCompany: " << obj.Firm::name << "\n";
	out << "\tProject: " << obj.name << "\n";
	out << "\tCategory: " << obj.category << "\n";
	out << "\tParking lots: " << obj.number << "\n";
	out << "\tBeginning of Project: " << obj.startDate << "\n";
	out << "\tDeadline: " << obj.endDate << "\n";
	out << "\tContents : " << obj.content << "\n";
	out << "\tPrice : " << obj.price << "\n";
	out << "\t___________________________________________________________\n";

	return out;
}
