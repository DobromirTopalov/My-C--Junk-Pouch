#include "Firm.h"

Firm::Firm(Stringy name)
{
	this->name = name;
}

Firm::~Firm()
{
	;
}

Firm::Firm(const Firm& obj)
{
	this->name = obj.name;
}

Firm& Firm:: operator=(const Firm& obj)
{
	this->name = obj.name;
	return *this;
}

std::ostream& operator<<(std::ostream & out, const Firm& obj)
{
	out << obj.name;
	return out;
}

std::istream& operator >> (std::istream& in, const Firm& obj)
{
	in >> obj.name;
	return in;
}