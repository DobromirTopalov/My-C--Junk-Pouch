#include <iostream>
#include <iomanip>
#include <cmath>

const double EPSILON = 0.001;

int twoNumCompare(int a, int b)
{
	return a <= b ? b : a;
}

int twoNumCompareSecond(int a, int b)
{
	if (a <= b)
		return b;
	else
		return a;
}

int fullCompare(int a, int b)
{
	if (a < b)
		return b;
	else if (a == b)
		return 0;
	else
		return a;
}

double compareDoubles(double one, double two)
{
	if (one < two)
		return two;
	else if (one == two)
		return 0;
	else
		return one;
}

////////////////////////////////////////////////////////////////////
bool approximatelyEqual(double a, double b)
{
	return abs(a - b) <= ((abs(a) < abs(b) ? abs(b) : abs(a)) * EPSILON);
}

bool essentiallyEqual(double a, double b)
{
	return abs(a - b) <= ((abs(a) > abs(b) ? abs(b) : abs(a)) * EPSILON);
}

bool definitelyGreaterThan(double a, double b)
{
	return (a - b) > ((abs(a) < abs(b) ? abs(b) : abs(a)) * EPSILON);
}

bool definitelyLessThan(double a, double b)
{
	return (b - a) > ((abs(a) < abs(b) ? abs(b) : abs(a)) * EPSILON);
}

bool epsiloncomp(double a, double b)
{
	return fabs(a - b) < EPSILON;
}
int main()
{
	int a, b;
	std::cout << "Give two numbers to compare: ";
	//std::cin >> a >> b;
	//std::cout << twoNumCompare(a, b)<<"\n";
	//std::cout << twoNumCompareSecond(a, b)<<"\n";
	//std::cout << fullCompare(a, b)<<"\n";

	double c, d;
	std::cin >> c >> d;
	//std::cout << compareDoubles(c, d) << "\n";
	//double e = 0.0001 - 0.00005 - 0.00005;
	
	//std::cout << std::boolalpha<<epsiloncomp(c,d);
	std::cout <<std::setprecision(3)<< c - d << "\n";					//три цифри без значение запетаята
	
	std::cout <<std::fixed << std::setprecision(10) << c - d << "\n";	//три цифри винаги общо със запетая
	return 0;
}