#pragma once
#include "Project.h"

class Highway :public Project
{
private:
	unsigned int length;
	Stringy category;
public:
	Highway(Stringy nameOne = "", Stringy nameTwo = "", Stringy startDate = "", Stringy endDate = "", float price = 0.0, Stringy content = "", Stringy category = "", unsigned int lenght = 0);
	~Highway();
	Highway(const Highway& obj);
	Highway& operator=(const Highway& obj);

	Stringy addContent(char* buffer);
	
	friend std::ostream& operator<<(std::ostream& out, const Highway& obj);
	
	Stringy getCategory();
	unsigned int getNumber();

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
		getline(inFile, category);

		inFile >> length >> price;
		//inFile >> Firm::name >> name >> startDate >> endDate >> content >> category >> length >> price;
		return inFile;
	}

};

	/*
	virtual Chicken* printProduct() const {
		return new Chicken(*this);
	}
	*/