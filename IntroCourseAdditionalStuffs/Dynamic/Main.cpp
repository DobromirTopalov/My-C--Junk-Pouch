#include <iostream>
#include "Dynamic.h"

std::ostream& operator<<(std::ostream& output,Dynamic& obj)						// predefiniraneto na << i >> kude tochno se izvurshva
{																				// vutre v klasa,otvun,tuk,v source fail za klasa ????
																				// kude i kakvi #include trqbva da sloja
	if (obj.getBox() != nullptr)												// i sushto kakvi izklucheniq trqbva da prihvanem ili da
	{																			// obrabotim po nqkakav nachin(s try/catch ili std::cout)
		output << obj.getBox() << " and " << obj.getSize() << "\n";
		return output;
	}
	else
	{
		std::cout << "Bad input!\n";
	}
}

int main() {

	// . . . .	 dokarah go da bachka donqkade...Dava warnings ama raboti ei :D.
	// . . . .

	return 0;
}