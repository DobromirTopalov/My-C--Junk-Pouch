#pragma once

class Rational_Num
{
	int numerator;
	int denominator;

public:
	Rational_Num();
	Rational_Num(int num,int denom);
	Rational_Num operator+(const Rational_Num& obj) const;
	
	Rational_Num operator*=(const Rational_Num& obj);
	Rational_Num operator--();
	Rational_Num operator++();
	Rational_Num operator/(int num);
	
	operator float() const;

	int NOK(int a,int b) const;						// http://stackoverflow.com/questions/10956543/gcd-function-in-c-sans-cmath-library
	int NOD(int a,int b) const;

	int getNumerator();
	int getDenominator();
	~Rational_Num();
};
