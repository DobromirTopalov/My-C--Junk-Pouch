#include <iostream>
#include <fstream>

#include "Stringy.h"
#include "Firm.h"
#include "Block.h"
#include "CarPark.h"
#include "Highway.h"
#include "House.h"
#include "Project.h"

	/*
	*/

int Project:: position= 0;

int main()
{
	CarPark first("EngBD", "Polygon", "02.02.2016", "07.11.2017", 137690.47, "A big parking space with security guards and carwash nearby", "Ultra Wide", 25000);
	Block second("EngBD", "Albena_26A", "04.08.1989", "06.07.1991", 687145.19, "Flat Appartment Complex with its own kindergarden,shops,nature parks and parking/biking infrastructure", "A++", 960);
	Highway third("EngBD", "Bulgaria", "11.03.2007", "12.12.2012", 908541237.47, "Biggest highway project,connects every town in the country and has 8 lanes with 2xEmergency lanes.A lot of gas/electric stations as well as places to have dinner and WC", "Extreme Lux", 901456);
	Block fifth("EngBD", "Albena_13B", "01.01.2011", "02.02.2013", 356664, "Small Flat Appartment Complex within the town of Kirdjhaaalye", "Z--", 120);
	House fourth("EngBD", "The Black Pearl", "07.07.2000", "--.--.----", 99999999999, "Everything in the known and unknown world", 42);


	Project* pointer[5];
	pointer[0] = &first;
	pointer[1] = &second;
	pointer[2] = &third;
	pointer[3] = &fourth;
	pointer[4] = &fifth;

	std::ofstream file;
	file.open("My Projects.txt", std::ios::out | std::ios::trunc);
	if (file.is_open())
	{

		for (int i = 0; i < 5; i++)
		{
			file << "\tCompany: " << pointer[i]->getNameFirm() << "\n";
			file << "\tProject: " << pointer[i]->getName() << "\n";
			if (((pointer[i]->getCategory()).StringyCompare(pointer[i]->getCategory(), "")) != 0)
				file << "\tCategory: " << pointer[i]->getCategory() << "\n";

			file << "\tFloors: " << pointer[i]->getNumber() << "\n";
			file << "\tBeginning of Project: " << pointer[i]->getstartDate() << "\n";
			file << "\tDeadline: " << pointer[i]->getendDate() << "\n";
			file << "\tContents : " << pointer[i]->getContent() << "\n";
			file << "\tPrice : " << pointer[i]->getPrice() << "\n";
			file << "\t___________________________________________________________\n";

		}
		file << "\n\nFile successfully written!GJ!\n";
		std::cout << "Process completed successfully!\n";
	}
	else
	{
		std::cout << "Unable to find or open file with this name and format!Try again.\n";
	}
	if (!(file.good()))
	{
		std::cout << "End of file/Fail input character/Bad failure conditions met!\n";
	}

	file.close();



	std::ofstream dataFile;
	dataFile.open("dataFile.txt", std::ios::out | std::ios::trunc);
	if (!(dataFile.is_open()))
	{
		std::cout << "Unable to find or open file with this name and format!Try again.\n";
	}
	else
	{
		dataFile << "\n";
		for (int i = 0; i < 5; i++)
		{
			pointer[i]->operator<<(dataFile);
		}
		
		std::cout << "Data saved!\n";
	}
	if (!(file.good()))
	{
		std::cout << "End of file/Fail input character/Bad failure conditions met!\n";
	}
	dataFile.close();

	/////////////////////////////////// good



	std::ifstream inputData;
	inputData.open("dataFile.txt", std::ios::in | std::ios::beg | std::ios::app);
	if (inputData.is_open())
	{
		for (int i = 0; i < 5; i++)
		{
			pointer[i]->operator>>(inputData);
		}
		std::cout << "Data Initialized!\n";
	}
	else
	{
		std::cout << "Bad failure!\n";
	}
	inputData.close();






	//////////////////////////////// good



	std::ofstream fileTestInput;
	fileTestInput.open("fileTestInput.txt", std::ios::out | std::ios::trunc);
	if (!(fileTestInput.is_open()))
	{
		std::cout << "Unable to find or open file with this name and format!Try again.\n";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			fileTestInput << pointer[i]->getNameFirm() << "\n";
			fileTestInput << pointer[i]->getName() << "\n";
			fileTestInput << pointer[i]->getstartDate() << "\n";
			fileTestInput << pointer[i]->getendDate() << "\n";
			fileTestInput << pointer[i]->getContent() << "\n";

			if (((pointer[i]->getCategory()).StringyCompare(pointer[i]->getCategory(), "")) != 0)
				fileTestInput << pointer[i]->getCategory() << "\n";

			fileTestInput << pointer[i]->getNumber() << "\n";

			fileTestInput << pointer[i]->getPrice();
		}
		std::cout << "Data saved!\n";
	}
	if (!(fileTestInput.good()))
	{
		std::cout << "End of file/Fail input character/Bad failure conditions met!\n";
	}
	fileTestInput.close();

	return 0;
}