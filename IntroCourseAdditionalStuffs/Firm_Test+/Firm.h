#pragma once
#include "Stringy.h"

class Firm
{
protected:
	Stringy name;
public:
	Firm(Stringy name="");
	virtual ~Firm();
	Firm(const Firm& obj);
	Firm& operator=(const Firm& obj);
	
	friend std::ostream& operator<< (std::ostream& out, const Firm& obj);
	friend std::istream& operator>> (std::istream& in, const Firm& obj);
};