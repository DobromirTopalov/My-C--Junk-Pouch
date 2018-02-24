#include <iostream>
#include "Stringo.h"
#include "Pencil.h"
#include "Marker.h"
#include "Brand.h"
#include <fstream>

int main()
{
	Marker Black("DobaOOD", 10, "Black", 13689);
	Marker Green("DobaEAD", 15, "Green", 17804);
	Pencil Red("DobaOOD", 18, "Red", 98010);
	Pencil Blue("DobaEAD", 25, "Blue", 11111);

	Brand* pointer[4];
	pointer[0] = &Black;
	pointer[1] = &Green;
	pointer[2] = &Red;
	pointer[3] = &Blue;


	std::ofstream data;
	data.open("DatabaseSample.txt", std::ios::out | std::ios::trunc);
	if (data.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			pointer[i]->operator<<(data);
		}
		std::cout << "Process completed!\n";
	}
	else
	{
		std::cout << "Failed operation!\n";
	}
	data.close();


	/*
	std::ofstream dataTwo;
	dataTwo.open("DatabaseReal.txt", std::ios::out | std::ios::trunc);
	if (dataTwo.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			pointer[i]->operator<<(dataTwo);
		}
		std::cout << "Process completed!\n";
	}
	else
	{
		std::cout << "Failed operation!\n";
	}
	dataTwo.close();

	*/


	std::ifstream input;
	input.open("DatabaseReal.txt", std::ios::in | std::ios::beg | std::ios::app);
	if (input.is_open())
	{
		for (int i = 0; i < 4; i++)
		{
			pointer[i]->operator >> (input);
		}
		std::cout << "Completed!\n";
	}
	else
	{
		std::cout << "Failed operation!\n";
	}
	input.close();

	//////////////////////////////////////////////////////////////////////////////

	std::cout << "\n\n";

	for (int i = 0; i < 4; i++)
	{
		std::cout <<"\n#"<<i+1<< "____________________________\n";
		pointer[i]->operator<<(std::cout);
		std::cout << "\n";
	}

	std::cout << "\n\n";
	return 0;
}