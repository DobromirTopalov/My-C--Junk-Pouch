#include "Header.h"

Rational_Num::Rational_Num()
{
	numerator = 0;
	denominator = 0;
}

Rational_Num::Rational_Num(int num, int denom)
{
	numerator = num;
	denominator = denom;
}

Rational_Num Rational_Num::operator+(const Rational_Num& obj) const
{
	int commondivisor = NOD(this->denominator,obj.denominator);
	int newnumerator = ((this->numerator*(commondivisor / this->denominator)) + (obj.numerator*(commondivisor / obj.denominator)));
	
	Rational_Num newrational;
	newrational.numerator = newnumerator;
	newrational.denominator = commondivisor;

	return newrational;
}

Rational_Num Rational_Num::operator*=(const Rational_Num& obj)
{
	Rational_Num temporary;
	temporary.numerator = (this->numerator)*obj.numerator;
	temporary.denominator = (this->denominator)*obj.denominator;

	int commondivisor = NOD(temporary.numerator, temporary.denominator);
	numerator = temporary.numerator;
	denominator = temporary.denominator;
	
	temporary.numerator = commondivisor / denominator;
	temporary.denominator = commondivisor/numerator;

	return temporary;
}

Rational_Num Rational_Num::operator--()
{
	int temp = numerator;
		numerator = denominator;
		denominator = temp;
	return *this;
}

Rational_Num Rational_Num::operator++()
{
	int temp = numerator;
		numerator = denominator;
		denominator = temp;
	return *this;
}

Rational_Num Rational_Num::operator/(int num)
{
	numerator=numerator/ num;
	denominator=denominator/ num;

	return *this;
}

Rational_Num::operator float() const
{
	return numerator*1.0f/denominator;
}

int Rational_Num::NOK(int a, int b) const
{
	int tmp;
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp % a;
	}
	return a;
}

int Rational_Num::NOD(int a,int b) const
{
	return (a * b / NOK(a,b));
}

int Rational_Num::getNumerator()
{
	return numerator;
}

int Rational_Num::getDenominator()
{
	return denominator;
}

Rational_Num::~Rational_Num()
{
	;
}