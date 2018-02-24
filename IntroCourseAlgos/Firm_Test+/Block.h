#pragma once
#include "Project.h"

class Block :public Project
{
private:
	unsigned int floor;
	Stringy category;
public:
	Block(Stringy nameOne = "", Stringy nameTwo = "", Stringy startDate = "", Stringy endDate = "", float price = 0.0, Stringy content = "",Stringy category="",unsigned int floor=0);
	~Block();
	Block(const Block& obj);
	Block& operator=(const Block& obj);

	Stringy addContent(char* buffer);
	
	friend std::ostream& operator<<(std::ostream& out, const Block& obj);
	
	Stringy getCategory();
	unsigned int getNumber();

	std::ostream& operator<<(std::ostream& file)
	{

		file <<getNameFirm() << "\n";
		file << " " << getName() << "\n";
		file << " " << getstartDate() << "\n";
		file << " " << getendDate() << "\n";
		file << " " << getContent() << "\n";

		if (((getCategory()).StringyCompare(getCategory(), "")) != 0)
			file << " " << getCategory() << "\n";

		file << " " << getNumber() << "\n";

		file << " " << getPrice() << "\n";

		return file;

	}

	std::istream& operator >> (std::istream& inFile)
	{
		getline(inFile, Firm::name);
		getline(inFile, name);
		getline(inFile, startDate);
		getline(inFile, endDate);
		getline(inFile, content);
		getline(inFile, category);

		inFile >> floor >> price;
		//inFile >> Firm::name >> name >> startDate >> endDate >> content >> category >> floor >> price;
		return inFile;
	}

};

	/*
	virtual Egg* printProduct() const {
		return new Egg(*this);
	}
	*/