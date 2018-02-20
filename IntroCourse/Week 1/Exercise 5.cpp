/*Зад.5
Напишете програма, която разменя стойностите на две променливи.
    
Зад.5.1 Програмата да НЕ използва помощна променлива.

*/

#include <iostream>

int main()
{
	//Зад.5
	int a, b, swap;
	std::cin >> a >> b;
	
	swap = a;
	a = b;
	b = swap;

	std::cout << a << " and " << b<<"\n";

	//Зад.5.1
	int A, B;
	A = 4;
	B = 8;

	A = A + 4;
	B = B - 4;
	std::cout << A << " and " << B << "\n";


	return 0;
}