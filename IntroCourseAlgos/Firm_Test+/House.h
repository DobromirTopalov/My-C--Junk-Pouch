#pragma once
#include "Project.h"

class House:public Project
{
private:
	unsigned int number;

public:
	House(Stringy nameOne = "", Stringy nameTwo = "", Stringy birthDate = "", Stringy expDate = "", float price = 0.0, Stringy content = "", unsigned int number = 0);
	~House();
	House(const House& obj);
	House& operator=(const House& obj);

	Stringy addContent(char* buffer);
	Stringy getCategory();
	unsigned int getNumber();
	
	friend std::ostream& operator<<(std::ostream& out, const House& obj);

	std::ostream& operator<<(std::ostream& file)
	{
		file << getNameFirm() << "\n";
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

		inFile >> number >> price;

		//inFile >> Firm::name >> name >> startDate >> endDate >> content >> number >> price;
		return inFile;
	}


};
	/*
	virtual Manjon* printProduct() const {
		return new Manjon(*this);
	}
	*/
