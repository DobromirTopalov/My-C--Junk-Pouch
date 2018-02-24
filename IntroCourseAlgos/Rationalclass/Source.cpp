#include <iostream>
#include "Header.h"

int main()
{
	Rational_Num one(1, 10);						// constructors
	Rational_Num two(1, 10);
	Rational_Num three(1, 10);
	Rational_Num four(1, 10);
	Rational_Num five(1, 10);
	Rational_Num six(1, 10);
	Rational_Num seven(1, 10);
	Rational_Num eight(1, 10);
	Rational_Num nine(1, 10);
	Rational_Num ten(1, 10);


	Rational_Num first(2,5), second(6,9);			// tests

		Rational_Num test2 = first+second;			// operator +
		std::cout << test2.getNumerator() << "/" << test2.getDenominator() << "\n";

		Rational_Num test3 = first *= second;		// operator *=
		std::cout << test3.getNumerator() << "/" << test3.getDenominator() << "\n";

		Rational_Num test4 = --first;				// operator --
		std::cout << test4.getNumerator() << "/" << test4.getDenominator() << "\n";

		Rational_Num test5 = ++first;				// operator ++
		std::cout << test5.getNumerator() << "/" << test5.getDenominator() << "\n";

		Rational_Num test6 = second / 3;			//operator /
		std::cout << test6.getNumerator() << "/" << test6.getDenominator() << "\n";

		std::cout << "_____________________________________________________________________\n";


	Rational_Num test1 = one+two+three+four+five+six+seven+eight+nine+ten;
	std::cout<<((float)test1 == 1.0f)<<"\n";											// true
	std::cout << (float)test1 << "\n";													// 1
	std::cout << test1.getNumerator() << "/" << test1.getDenominator() << "\n";			// 10/10

	Rational_Num bahti(4, 8);
	std::cout << "_____________________________________________________________________\n";
	std::cout << bahti<<bahti;

	return 0;
}