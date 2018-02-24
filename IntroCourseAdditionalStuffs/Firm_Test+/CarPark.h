#pragma once
#include "Project.h"

class CarPark :public Project
{
private:
	unsigned int number;
	Stringy category;
public:
	CarPark(Stringy nameOne = "", Stringy nameTwo = "", Stringy startDate = "", Stringy endDate = "", float price = 0.0, Stringy content = "", Stringy category = "", unsigned int number = 0);
	~CarPark();
	CarPark(const CarPark& obj);
	CarPark& operator=(const CarPark& obj);

	Stringy addContent(char* buffer);
	Stringy getCategory();
	unsigned int getNumber();

	friend std::ostream& operator<<(std::ostream& out, const CarPark& obj);

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

	std::istream& operator>> (std::istream& inFile)
	{
		//getline<char, std::char_traits<char>, std::allocator<char>>(inFile, Firm::name);
		//getline(inFile, static_cast<Stringy&>(Firm::name));
		
		getline(inFile, Firm::name);
		getline(inFile, name);
		getline(inFile, startDate);
		getline(inFile, endDate);
		getline(inFile, content);
		getline(inFile, category);

		inFile >> number >> price;

		//inFile >> Firm::name >> name >> startDate >> endDate >> content >> category >> number >> price;

		return inFile;
	}

};

	/*
	virtual Feather* printProduct() const {
		return new Feather(*this);
	}
	*/
