/*Зад.2
Напишете програма, която намира лице на триъгълник по дадени страна и височина към нея.*/

#include <iostream>

int main()
{
	float a, h, area;
	std::cin >> a >> h;
	area = (a*h) / 2;
	std::cout << "Area of triangle = " << area<<"\n";




	return 0;
}