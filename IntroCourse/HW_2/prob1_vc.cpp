/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <iomanip>
#include <cmath>

void fillCoordinates(double arrayofcoordinates[], double arrayofcoordinates2[], int &numberofcoordinates) //okay
{
	for (int i = 0; i < numberofcoordinates * 2; i++)
	{
		std::cin >> arrayofcoordinates[i];
		arrayofcoordinates2[i] = arrayofcoordinates[i];
	}
}


bool intersectionTop(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - 2)) - ((2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((2 - 2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout<<"failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout<<"failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return checkIf;
}


bool intersectionRight(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - 5)*(y1 - 2)) - ((-2 - 2)*(x1 - 5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - 5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((5 - 5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return checkIf;
}


bool intersectionBottom(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - -2)) - ((-2 - -2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - -2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - -2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return checkIf;
}


bool intersectionLeft(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((-5 - -5)*(y1 - 2)) - ((-2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((-5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return checkIf;
}


double intersectionTopX(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - 2)) - ((2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((2 - 2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout<<"failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout<<"failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return X;
}


double intersectionTopY(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - 2)) - ((2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((2 - 2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout<<"failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout<<"failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return Y;
}


double intersectionRightX(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - 5)*(y1 - 2)) - ((-2 - 2)*(x1 - 5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - 5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((5 - 5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return X;
}


double intersectionRightY(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - 5)*(y1 - 2)) - ((-2 - 2)*(x1 - 5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - 5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((5 - 5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return Y;
}

double intersectionBottomX(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - -2)) - ((-2 - -2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - -2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - -2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return X;
}


double intersectionBottomY(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((5 - -5)*(y1 - -2)) - ((-2 - -2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - -2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - -2)*(x2 - x1)) - ((5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return Y;
}


double intersectionLeftX(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((-5 - -5)*(y1 - 2)) - ((-2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((-5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return X;
}

double intersectionLeftY(double x1, double y1, double x2, double y2) //http://www-cs.ccny.cuny.edu/~wolberg/capstone/intersection/Intersection%20point%20of%20two%20lines.html
{
	double denominator, numerator, numerator2, ua, ub, X, Y;
	bool checkIf = false;
	numerator = ((-5 - -5)*(y1 - 2)) - ((-2 - 2)*(x1 - -5));
	numerator2 = ((x2 - x1)*(y1 - 2)) - ((y2 - y1)*(x1 - -5));
	denominator = ((-2 - 2)*(x2 - x1)) - ((-5 - -5)*(y2 - y1));

	if (denominator == 0)
	{
		//std::cout << "failp";//do nothing because lines are parallel
	}
	else if (denominator == 0 && numerator == 0 && numerator2 == 0)
	{
		//std::cout << "failc";//do nothing because lines are coincident
	}
	else
	{
		ua = numerator / denominator;
		ub = numerator2 / denominator;
		//std::cout << ua << " " << ub << "\n";

		if (((0.000000000001 <= ua || 0 <= ua) && ua <= 0.99999999999999999) && ((0.000000000001 <= ub || 0 <= ub) && ub <= 0.99999999999999999))
		{
			checkIf = true;
			X = x1 + ua*(x2 - x1);
			Y = y1 + ua*(y2 - y1);
			//std::cout << X << " " << Y << "\n";
		}
		else
		{
			checkIf = false;
		}
	}
	//std::cout << checkIf << "\n";

	return Y;
}




void changecoordinates(double arrayofcoordinates[], double arrayofcoordinates2[], int &numberofcoordinates) //https://en.wikipedia.org/wiki/Line%E2%80%93line_intersection
{

	for (int i = 0; i < numberofcoordinates * 2 - 1; i += 2)
	{
		////////////a vutre b vun
		if (((arrayofcoordinates[i]<5 && arrayofcoordinates[i]>-5) && (arrayofcoordinates[i + 1]<2 && arrayofcoordinates[i + 1]>-2)) && ((arrayofcoordinates[i + 2] > 5 || arrayofcoordinates[i + 2] < -5) || (arrayofcoordinates[i + 3] > 2 || arrayofcoordinates[i + 3] < -2)))
		{
			double x1, y1, x2, y2;
			x1 = arrayofcoordinates[i];
			y1 = arrayofcoordinates[i + 1];
			x2 = arrayofcoordinates[i + 2];
			y2 = arrayofcoordinates[i + 3];

			if (intersectionTop(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i + 2] = intersectionTopX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 3] = intersectionTopY(x1, y1, x2, y2);
			}
			else if (intersectionTop(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionRight(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i + 2] = intersectionRightX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 3] = intersectionRightY(x1, y1, x2, y2);
			}
			else if (intersectionRight(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionBottom(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i + 2] = intersectionBottomX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 3] = intersectionBottomY(x1, y1, x2, y2);
			}
			else if (intersectionBottom(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionLeft(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i + 2] = intersectionLeftX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 3] = intersectionLeftY(x1, y1, x2, y2);
			}
			else if (intersectionLeft(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}
		}

		////////////a vun b vutre
		if (((arrayofcoordinates[i + 2]<5 && arrayofcoordinates[i + 2]>-5) && (arrayofcoordinates[i + 3]<2 && arrayofcoordinates[i + 3]>-2)) && ((arrayofcoordinates[i] > 5 || arrayofcoordinates[i] < -5) || (arrayofcoordinates[i + 1] > 2 || arrayofcoordinates[i + 1] < -2)))
		{
			double x1, y1, x2, y2;
			x1 = arrayofcoordinates[i];
			y1 = arrayofcoordinates[i + 1];
			x2 = arrayofcoordinates[i + 2];
			y2 = arrayofcoordinates[i + 3];

			if (intersectionTop(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i] = intersectionTopX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 1] = intersectionTopY(x1, y1, x2, y2);
			}
			else if (intersectionTop(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionRight(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i] = intersectionRightX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 1] = intersectionRightY(x1, y1, x2, y2);
			}
			else if (intersectionRight(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionBottom(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i] = intersectionBottomX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 1] = intersectionBottomY(x1, y1, x2, y2);
			}
			else if (intersectionBottom(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}

			if (intersectionLeft(x1, y1, x2, y2) == true)
			{
				arrayofcoordinates2[i] = intersectionLeftX(x1, y1, x2, y2);
				arrayofcoordinates2[i + 1] = intersectionLeftY(x1, y1, x2, y2);
			}
			else if (intersectionLeft(x1, y1, x2, y2) == false)
			{
				;//do nothing
			}
			
		}


		////////////a na liniqta i b na liniqta
		
		if ((((arrayofcoordinates[i] <= 5.0099999999999999) && (arrayofcoordinates[i] >= -5.0099999999999999)) 
		&& (arrayofcoordinates[i + 1] == 2.0 || arrayofcoordinates[i + 1] == -2.0))
			|| (((arrayofcoordinates[i+1] <= 2.0099999999999999) && (arrayofcoordinates[i+1] >= -2.0099999999999999))
				&& (arrayofcoordinates[i] == 5.0 || arrayofcoordinates[i] == -5.0)))
			
		{
			arrayofcoordinates2[i] = arrayofcoordinates[i];
			arrayofcoordinates2[i + 1] = arrayofcoordinates[i + 1];
		}
		
		////////////a vun b vun
		if (((arrayofcoordinates[i + 2] > 5 || arrayofcoordinates[i + 2] < -5) || (arrayofcoordinates[i + 3] > 2 || arrayofcoordinates[i + 3] < -2)) && ((arrayofcoordinates[i] > 5 || arrayofcoordinates[i] < -5) || (arrayofcoordinates[i + 1] > 2 || arrayofcoordinates[i + 1] < -2)))
		{
			//do nothing;
		}
	}
}

void filldistancePointToPoint(double arrayofcoordinates[], double arrayofcoordinates2[], double arrayofcoordinates3[], int &numberofcoordinates) //okay
{
	int k = 0;
	for (int i = 0; i < (numberofcoordinates - 1) * 2; i += 2)
	{
		if (((arrayofcoordinates[i] != arrayofcoordinates3[i]) || (arrayofcoordinates[i+1] != arrayofcoordinates3[i+1]))
			&& ((arrayofcoordinates[i+2] != arrayofcoordinates3[i+2]) || (arrayofcoordinates[i+3] != arrayofcoordinates3[i+3])))
		{
			arrayofcoordinates2[k] = 0;
		}
		else
		{
		arrayofcoordinates2[k] = sqrt(pow((arrayofcoordinates[i + 2] - arrayofcoordinates[i]), 2) + pow((arrayofcoordinates[i + 3] - arrayofcoordinates[i + 1]), 2));
		}
		k++;
	}
}

double sumApproxDistance(double arrayofcoordinates2[], int &numberofcoordinates) //okay
{
	const double PI = 3.14;
	double sum = 0;
	for (int i = 0; i < numberofcoordinates - 1; i++)
	{
		double x = arrayofcoordinates2[i];
		sum = sum + (((PI*x) / 2) + x) / 2;
	}
	return sum;
}


int main()
{
	int N;
	std::cin >> N;

	double fillchangecoordinates[10000];
	double coordinates[10000];
	fillCoordinates(coordinates, fillchangecoordinates, N);

	double distancePointToPoint[10000];
	changecoordinates(coordinates, fillchangecoordinates, N);

	filldistancePointToPoint(fillchangecoordinates, distancePointToPoint, coordinates, N);

	std::cout << std::fixed;
	std::cout << std::setprecision(3) << sumApproxDistance(distancePointToPoint, N);
	std::cout <<"\n";

	return 0;
}