/*Зад.2
Да се прочетат коефициентите на квадратно уравнение и да се определи дали то има реални корени и колко на брой са те - 1 или 2 
(Приемаме, че за целта е достатъчно дискриминантата на уравнението да е >= 0).
*/

#include <iostream>

int main()
{
	float a, b, c, D;
	std::cin >> a >> b >> c;
	D = (b*b) - (4 * a*c);

	if (D > 0)
	{
		std::cout << "equation has 2 real roots \n";
	}
	else if (D == 0)
	{
		std::cout << "equation has 1 real root \n";
	}
	else
	{
		std::cout << "equation has no answer \n";
	}


	return 0;
}