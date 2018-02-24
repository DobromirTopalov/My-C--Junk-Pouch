#include "Project.h"

Project::Project(Stringy nameOne,Stringy nameTwo, Stringy startDate, Stringy endDate, float price, Stringy content):Firm(nameOne)
{
	this->name = nameTwo;
	this->startDate = startDate;
	this->endDate = endDate;
	this->price = price;
	this->content = content;
}

Project::~Project()
{
	//do nothing
	;
}

Project::Project(const Project& obj)
{
	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;
}

Project& Project:: operator=(const Project& obj)
{
	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;
	
	return *this;
}

Stringy Project:: getNameFirm()
{
	return Firm::name;
}

Stringy Project:: getName()
{
	return name;
}

Stringy Project:: getstartDate()
{
	return startDate;
}

Stringy Project:: getendDate()
{
	return endDate;
}

float Project:: getPrice()
{
	return price;
}

Stringy Project:: getContent()
{
	return content;
}