#include <iostream>
#include "Person.h"
#include "Worker.h"
#include <fstream>


std::ostream& operator<<(std::ostream& output, Worker& obj)
{
	output << obj.getAddress() << " " << obj.getTown() << " " << obj.getYearsOfWorking()<<" "<<obj.getAge()<<" "<<obj.getName() << "\n";
	return output;
}

std::ostream& operator<<(std::ostream& output, Person& obj)
{
	output << obj.getAge() << " " << obj.getName() << "\n";
	return output;
}
int main()
{
	Person dobata("Dobri",19);
	std::cout << dobata.getName() << " is " << dobata.getAge() << " years old\n";

	Worker pepe("Kolio",21,"Pepe//asd//SOfia", "BGovegrad", 12);
	std::cout <<pepe.getName()<< " " <<pepe.getAge() << " " <<pepe.getAddress()<<" "<<pepe.getTown()<<" "<<pepe.getYearsOfWorking()<<"\n";

	Worker babe = pepe;
	std::cout << babe.getName() << " " << babe.getAge() << " " << babe.getAddress() << " " << babe.getTown() << " " << babe.getYearsOfWorking() << "\n";

	Worker nene;
	nene = pepe;
	std::cout << nene.getName() << " " << nene.getAge() << " " << nene.getAddress() << " " << nene.getTown() << " " << nene.getYearsOfWorking() << "\n";

	std::cout << nene;
	std::cout << "______________________________________________________file\n";

	Worker newWorker("Iordan Georgiev", 38, "EU,Bulgaria,Sofia,\"Studentski grad\" #-42B", "Kurdjali", 6);
	Person newPerson("Petur Iordanov", 12);

	std::ofstream file("Testing.txt", std::ios::out | std::ios::trunc);
	if (!file.is_open())
	{
		std::cout << "Unable to open the file.Please try again...\n";
	}
	else
	{
		std::cout << "\nFile successfully created!\n";

		file << "#1 |  " << newWorker.getName() << " is " << newWorker.getAge() << " years old and lives at " << newWorker.getAddress() << ".\nTown of birth: "
			<< newWorker.getTown() << "\nExperience so far: " << newWorker.getYearsOfWorking() << " years\n\n\n";

		file << "#2 |  " << newPerson.getName() << " is " << newPerson.getAge() << " years old!\n";

		file.close();
	}








	return 0;
}