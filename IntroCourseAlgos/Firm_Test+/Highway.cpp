#include "Highway.h"

Highway::Highway(Stringy nameOne, Stringy nameTwo, Stringy startDate, Stringy endDate, float price, Stringy content, Stringy category, unsigned int length)
	:Project(nameOne, nameTwo, startDate, endDate, price, content)
{
	this->length = length;
	this->category = category;
}

Highway::~Highway()
{
	;
}

Highway::Highway(const Highway& obj)
{
	this->length = obj.length;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;


	this->Firm::name = obj.Firm::name;

}

Highway& Highway:: operator=(const Highway& obj)
{
	this->length = obj.length;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;

	this->Firm::name = obj.Firm::name;

	return *this;
}

Stringy Highway::addContent(char* buffer)
{
	Stringy temp = (buffer);
	this->content = temp.StringyCat(content, temp);
	return content;
}

Stringy Highway::getCategory()
{
	return category;
}
unsigned int Highway::getNumber()
{
	return length;
}

std::ostream& operator<<(std::ostream& out, const Highway& obj)
{
	out << "\tCompany: " << obj.Firm::name << "\n";
	out << "\tProject: " << obj.name << "\n";
	out << "\tCategory: " << obj.category << "\n";
	out << "\tLength in km(units): " << obj.length << "\n";
	out << "\tBeginning of Project: " << obj.startDate << "\n";
	out << "\tDeadline: " << obj.endDate << "\n";
	out << "\tContents : " << obj.content << "\n";
	out << "\tPrice : " << obj.price << "\n";
	out << "\t___________________________________________________________\n";

	return out;

}

