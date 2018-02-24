#include "Block.h"

Block::Block(Stringy nameOne, Stringy nameTwo, Stringy startDate, Stringy endDate, float price, Stringy content, Stringy category, unsigned int floor)
	:Project(nameOne,nameTwo,startDate,endDate,price,content)
{
	this->floor= floor;
	this->category = category;
}

Block::~Block()
{
	;
}

Block::Block(const Block& obj)
{
	this->floor = obj.floor;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;

	this->Firm::name = obj.Firm::name;	
}

Block& Block:: operator=(const Block& obj)
{
	this->floor = obj.floor;
	this->category = obj.category;

	this->name = obj.name;
	this->startDate = obj.startDate;
	this->endDate = obj.endDate;
	this->price = obj.price;
	this->content = obj.content;

	this->Firm::name = obj.Firm::name;
	
	return *this;
}

Stringy Block::addContent(char* buffer)
{
	Stringy temp=(buffer);
	this->content=temp.StringyCat(content,temp);
	return content;
}

Stringy Block:: getCategory()
{
	return category;
}
unsigned int Block::getNumber()
{
	return floor;
}


std::ostream& operator<<(std::ostream& out, const Block& obj)
{
	out << "\tCompany: " << obj.Firm::name<<"\n";
	out << "\tProject: " << obj.name << "\n";
	out << "\tCategory: " << obj.category << "\n";
	out << "\tFloors: " << obj.floor << "\n";
	out << "\tBeginning of Project: " << obj.startDate << "\n";
	out << "\tDeadline: " << obj.endDate << "\n";
	out << "\tContents : " << obj.content << "\n";
	out << "\tPrice : " << obj.price << "\n";
	out << "\t___________________________________________________________\n";

	return out;

}


//			Company: KFC 
//			Project: Block
//			Category: A++
//			Floors: 56         
//			Beginning of Project: 09.08.2009
//			Deadline: 09.09.2009
//			Contents: ......................................
//			Price: 356522.89
// ________________________________________________________________