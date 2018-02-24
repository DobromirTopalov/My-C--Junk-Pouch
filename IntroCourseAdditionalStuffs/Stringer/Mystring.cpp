#include <iostream>
#include "Stringer.h"

int main()
{
	Stringer name("Dobromir");
	Stringer surname("Enchev");
	Stringer lastname("Topalov");

	Stringer subject("Creator of Stringer Class in C++ language");
	Stringer credits("		Tashaci.corp");

	std::cout << name.getStringer() << " " << surname.getStringer() << " " << lastname.getStringer() << "\n";
	std::cout << "_________________________________________" << "   \n";
	std::cout << subject.getStringer() << "\n";
	std::cout << credits.getStringer() << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	return 0;
}