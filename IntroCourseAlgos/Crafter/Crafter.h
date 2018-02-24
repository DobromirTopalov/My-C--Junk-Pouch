#pragma once
#include "Product.h"
#include <cstring>
#include <vector>
#include <iostream>

class Crafter
{
private:
	char* name;
	int yearsOfWorking;
	std::vector<Product> newproduct;

public:
	friend class Product;

	Crafter()
	{
		name = nullptr;
		yearsOfWorking = 0;
		newproduct.clear();
	}

	Crafter(const char* name, int number, Product something)
	{
		int length = strlen(name);
		char* newname = new char[length + 1];
		strcpy(newname, name);
		this->name = newname;
		this->yearsOfWorking = number;
		this->newproduct.push_back(something);

	}
	Crafter(const char* name, int number)
	{
		int length = strlen(name);
		char* newname = new char[length + 1];
		strcpy(newname, name);
		this->name = newname;
		this->yearsOfWorking = number;
		this->newproduct.clear();

	}

	Crafter(const Crafter& obj)
	{
		int length = strlen(obj.name);
		char* newname = new char[length + 1];

		strcpy(newname, obj.name);
		this->name = newname;
		this->yearsOfWorking = obj.yearsOfWorking;
		if(!obj.newproduct.empty())
		for (int i = 0; i < obj.newproduct.size(); i++)
		{
			newproduct.push_back(obj.newproduct[i]);
		}
		else
		{
			std::cout << "Error!\n";
		}

	}

	Crafter& operator=(const Crafter& obj)
	{
		if (this != &obj)
		{
			int length = strlen(obj.name);
			char* newname = new char[length + 1];

			strcpy(newname, obj.name);
			delete name;
			this->name = newname;
			this->yearsOfWorking = obj.yearsOfWorking;
			newproduct.clear();
			for (int i = 0; i < obj.newproduct.size(); i++)
			{
				newproduct.push_back(obj.newproduct[i]);
			}
		}
		return *this;
	}


	~Crafter()
	{
		delete name;
		newproduct.clear();
	}

	void initializeP()
	{
		char* names=new char[900];
		float numbers;
		std::cout << "Enter name of product and its price: \n";
		std::cin >> names >> numbers;
	
		Product temp;
		temp.setName(names);
		temp.setPrice(numbers);
		newproduct.push_back(temp);

	}

	std::vector<Product> getProduct()
	{
		return newproduct;
	}

	void printP()
	{
		for (int i = 0; i < newproduct.size(); i++)
		{
			std::cout << newproduct[i].getName() << " " << newproduct[i].getPrice() << "\n";
		}
	}
	char* getName()
	{
		return name;
	}
	int getYears()
	{
		return yearsOfWorking;
	}
};