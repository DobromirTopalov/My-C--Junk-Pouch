#pragma once
#include "Firm.h"

class Project :public Firm
{
protected:
	Stringy name;
	Stringy startDate;
	Stringy endDate;
	float price;
	Stringy content;
	
// https://stackoverflow.com/questions/270917/why-should-i-declare-a-virtual-destructor-for-an-abstract-class-in-c
		//abstract class - prevent calling destructor in case we delete the pointer that points to derived class
			//thus we have no memory leaks
	virtual ~Project(); 
public:
	static int position;
	Project(Stringy nameOne="",Stringy nameTwo = "", Stringy startDate = "", Stringy endDate = "", float price = 0.0, Stringy content = "");
	Project(const Project& obj);
	Project& operator=(const Project& obj);


	virtual Stringy addContent(char* buffer)=0;
	virtual std::ostream& operator<<(std::ostream& file) = 0;

	virtual std::istream& operator>>(std::istream& inFile) = 0;
	
	virtual Stringy getCategory() = 0;
	virtual unsigned int getNumber() = 0;


	Stringy getNameFirm();
	Stringy getName();
	Stringy getstartDate();
	Stringy getendDate();
	float getPrice();
	Stringy getContent();

	std::istream& getline(std::istream& inFile, Stringy& buffer)
	{
		char temp;
		buffer = "";
		
		inFile.ignore(1);
		while (inFile.get(temp) && (temp != '\n'))
		{
			buffer.StringyCat(buffer, temp);
			
		}
	
		//std::cout << buffer << " | ";
		
		return inFile;
	}


	//virtual Project* printProject() const = 0;
};

	/*
	std::istream& getline(std::istream& inside, Stringy& buffer, char delimeter = '\n')
	{
		char tempChar;
		buffer = "";

		inside.ignore(0);
		while (inside.get(tempChar) && (tempChar != delimeter))
		{
			buffer.StringyCat(buffer, tempChar);
		}
		std::cout << buffer << " | ";

		return inside;
	}
	 */