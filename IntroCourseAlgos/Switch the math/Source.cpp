#include <iostream>
#include <cmath>

double powerN(int number, double power)
{
	double result = 1;

	if (power == 0)
	{
		return 1;
	}
	else if (power > 0)
	{
		for (int i = power; i > 0; i--)
		{
			result *= number;
		}

		return result;
	}
	else if(power < 0)
	{
		power *= (-1);
		for (int i = power; i > 0; i--)
		{
				result *= number;
		}

		return 1/result;
	}
}

double absoluteN(double number)
{
	if (number > 0)
		return number;
	else if (number < 0)
		return number*(-1);
	else
		return 0;
}

double sqrootN(double number)
{
	if (number >= 0)
	{
		return pow(number, (0.5));
	}
}

double rootN(double number,double value)
{
	double power = 1.0 / value;
	if ((number >= 0) || (absoluteN(power)>=3.0))
	{
		return pow(number, power);
	}
}

int main()
{
	double a,b;
	std::cout << "Enter numbers: ";
	std::cin >> a >> b;
	std::cout << "Enter key: {P}ower | {A}bsoluteValue | {SQRT}2nd root | {R}oot of nth: ";
	char c;
	std::cin >> c;

	switch (c)
	{
	case 'P':
	case 'p':	std::cout << powerN(a, b);
				std::cout << "\n"; break;
	case 'A':
	case 'a':	std::cout << absoluteN(a);
				std::cout << "\n"; break;

	case 'S':
	case 's':	std::cout << sqrootN(b);
				std::cout << "\n"; break;

	case 'R':
	case 'r':	std::cout << rootN(a, b);
				std::cout << "\n"; break;

	default:
				std::cout << "Invalid key!\n"; break;
	}
	
	return 0;
}