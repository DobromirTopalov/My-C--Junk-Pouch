#include "House.h"

House::House(Stringy nameOne, Stringy nameTwo, Stringy startDate, Stringy endDate, float price, Stringy content,unsigned int number)
	:Project(nameOne, nameTwo, startDate, endDate, price, content)
{
	this->number = number;
}

House::~House()
{
	;
}

House::House(const House& obj)
{
	this->number = obj.number;
	
	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;


	this->Firm::name = obj.Firm::name;

}

House& House:: operator=(const House& obj)
{
	this->number = obj.number;
	
	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;

	this->Firm::name = obj.Firm::name;


	return *this;
}

Stringy House::addContent(char* buffer)
{
	Stringy temp = (buffer);
	this->content = temp.StringyCat(content, temp);
	return content;
}

Stringy House:: getCategory()
{
	return " ";
}
unsigned int House::getNumber()
{
	return number;
}

std::ostream& operator<<(std::ostream& out, const House& obj)
{
	out << "\tCompany: " << obj.Firm::name << "\n";
	out << "\tProject: " << obj.name << "\n";
	
	out << "\tRooms: " << obj.number << "\n";
	out << "\tBeginning of Project: " << obj.startDate << "\n";
	out << "\tDeadline: " << obj.endDate << "\n";
	out << "\tContents : " << obj.content << "\n";
	out << "\tPrice : " << obj.price << "\n";
	out << "\t___________________________________________________________\n";

	return out;
}
