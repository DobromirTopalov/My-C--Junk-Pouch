/*Зад.4
Напишете програма, която пресмята реалните корени на квадратно уравнение по зададени коефициенти. 
Ако уравнението не е квадратно или няма корени да се изведе подходящо съобщение.*/

#include <iostream>
#include <cmath>

int main()
{
	float a, b, c;
	std::cin >> a >> b >> c;
	float x1, x2;

	double dick = (b*b) - (4 * a*c);
	if (dick > 0)
	{
		x1 = (-(b) + sqrt(dick)) / (2 * a);
		x2 = (-(b) - sqrt(dick)) / (2 * a);
		std::cout << x1 << " and " << x2 << "\n";
	}
	else if (dick == 0)
	{
		x1=(-b) / 2 * a;
		x2 = x1;
		std::cout << x1 << "\n";
	}
	else
	{
		std::cout << "No solutions!\n";
	}

	
	return 0;
}