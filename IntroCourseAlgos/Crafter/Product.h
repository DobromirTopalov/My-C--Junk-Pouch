#pragma once

class Product
{
private:
	char* name;
	float price;

public:
	Product()
	{
		name = nullptr;
		price = 0;
	}

	Product(const char* name,float number)
	{
		int length = strlen(name);
		char* newname = new char[length + 1];
		strcpy(newname, name);
		this->name = newname;
		this->price = number;
	}

	Product(const Product& obj)
	{
		int length = strlen(obj.name);
		char* newname = new char[length + 1];

		strcpy(newname, obj.name);
		this->name = newname;
		this->price = obj.price;
	}
	Product& operator=(const Product& obj)
	{
		if (this != &obj)
		{
			delete name;
			int length = strlen(obj.name);
			char* newname = new char[length + 1];

			strcpy(newname, obj.name);
			this->name = newname;
			this->price = obj.price;
		}
		return *this;
	}

	~Product()
	{
		delete name;
	}

	void setName(const char*name)
	{
		int length = strlen(name);
		char* newname = new char[length + 1];
		strcpy(newname, name);
		delete name;
		this->name = newname;
	}
	void setPrice(float number)
	{
		price = number;
	}
	char* getName()
	{
		return name;
	}
	float getPrice()
	{
		return price;
	}

};