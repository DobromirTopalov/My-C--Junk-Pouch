/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 10
* @compiler VC
*
*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	double a1, b1, result1;
	double a2, b2, result2;
	double x1;
	double y1;
	cin >> a1 >> b1 >> result1;
	cin >> a2 >> b2 >> result2;

	double a = b1*result2;
	double b = b2*result1;
	double epsilon = 0.000001;

	bool equal_ab = abs(a - b) < epsilon;			// https://www.quora.com/How-do-I-compare-two-floats-in-C++
	bool notequal_ab = abs(a - b) > epsilon;		// https://www.quora.com/How-do-I-compare-two-floats-in-C++

	if ((b1*a2 - b2*a1) != 0)
	{
		x1 = (b1*result2 - b2*result1) / (b1*a2 - b2*a1);		/*Izvejdam q ot dvete lineini uravneniq,kato predstavqm y-cite chrez x-ovete.
																Tui kato dvata y-ka sa ravni,priravnqvam poluchenite izrazi za y-cite
																kato ot tam namiram predstavqne za x-sa*/
		if (a1 > 0 && b1 != 0)
		{
			y1 = (result1 - (a1*x1)) / b1;
			cout << setprecision(5) << x1 << " " << setprecision(5) << y1;
		}
		if (a1 < 0 && b1 != 0)
		{
			y1 = (result1 + (a1*x1)) / b1;
			cout << setprecision(5) << x1 << " " << setprecision(5) << y1;
		}
		if (a1 == 0 && b1 != 0 && result1 == 0)
		{
			y1 = 0;
			cout << setprecision(5) << x1 << " " << setprecision(5) << y1;
		}
		if (a1 == 0 && b1 != 0 && result1 != 0)
		{
			y1 = result1 / b1;
			cout << setprecision(5) << x1 << " " << setprecision(5) << y1;
		}

		if ((a1 == 0 && b1 == 0) && result1 != 0)
		{
			cout << "No solution";
		}
		if ((a1 == 0 && b1 == 0) && result1 == 0)
		{
			cout << "Many solutions";
		}
	}
	if (equal_ab && ((b1*a2 - b2*a1) == 0))
	{
		cout << "Many solutions";
	}

	if (notequal_ab && ((b1*a2 - b2*a1) == 0))
	{
		cout << "No solution";
	}

	cout << "\n";


	return 0;
}