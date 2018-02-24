/*Зад.0
Напишете програма, която по дадена температура по Целзий, 
извежда съответната температура по Фаренхайт.*/

#include <iostream>

int main()
{
	float tempC,tempF;
	std::cin >> tempC;

	tempF = (tempC*(1.8)) + 32;
	std::cout <<tempC<<" celsius is "<< tempF <<" in farenheit.\n";



	return 0;
}