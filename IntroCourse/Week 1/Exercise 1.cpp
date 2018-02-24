/*Зад.1
Напишете програма, която по дадена възраст(в години) извежда 
приблизителен брой на дните, часовете и секундите, които е живял човек.*/

#include <iostream>

int main()
{
	int age, days;
	unsigned long int hours,seconds;
	std::cin >> age;

	days = age * 365;
	hours = days * 24;
	seconds = hours * 60 * 60;

	std::cout << "You are: " << age << " years old! This is equal to:\n" << days << " days/" << hours << " hours/" << seconds << " seconds." << std:: endl;
	std::cout << "\n";



	return 0;
}