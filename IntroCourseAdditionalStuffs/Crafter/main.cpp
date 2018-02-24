#include <iostream>
#include "Crafter.h"
#include <fstream>

int main()
{

	
	Crafter dobata("Dobromir", 3);
	dobata.initializeP();
	dobata.initializeP();
	dobata.initializeP();
	
	Crafter vankata("Ivan", 7);
	vankata.initializeP();
	vankata.initializeP();
	vankata.initializeP();

	vankata = dobata;
	vankata.printP();

	std::ofstream file("Text.txt", std::ios::out | std::ios::trunc);
	if (!file.is_open())
	{
		std::cout << "Error opening the file!\n";
	}
	else
	{
		file << "Crafter: " << dobata.getName() << " with " << dobata.getYears() << " years of experience has build: \n";
		for (int i = 0; i < dobata.getProduct().size(); i++)
		{
			file<<(dobata.getProduct())[i].getName() << " " << (dobata.getProduct())[i].getPrice() << "\n\n\n";
		}

		file << "Crafter: " << vankata.getName() << " with " << vankata.getYears() << " years of experience has build: \n";
		for (int i = 0; i < vankata.getProduct().size(); i++)
		{
			file << (vankata.getProduct())[i].getName() << " " << (vankata.getProduct())[i].getPrice() << "\n\n\n";
		}
	}

	file.close();
	
	
	return 0;
}