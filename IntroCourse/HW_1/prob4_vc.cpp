/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char XKing, XFigure;
	int YKing, YFigure;
	char Figure;

	cin >> Figure >> XFigure >> YFigure >> XKing >> YKing;

	if ((XKing >= 97 && XKing <= 104) && (YKing >= 1 && YKing <= 8))
	{
		if ((XFigure >= 97 && XFigure <= 104) && (YFigure >= 1 && YFigure <= 8))
		{
			////////////////////////////////////////Queen(Q)
			if (Figure == 81)
			{
				if ((YKing == YFigure) || (XKing == XFigure))
				{
					cout << "Yes";
				}
				else if (abs(XFigure - XKing) == abs(YFigure - YKing))
				{
					cout << "Yes";
				}
				else
				{
					cout << "No";
				}
			}

			////////////////////////////////////////Rook(R)
			if (Figure == 82)
			{
				if ((YKing == YFigure) || (XKing == XFigure))
				{
					cout << "Yes";
				}
				else
				{
					cout << "No";
				}
			}

			////////////////////////////////////////Bishop(B)
			if (Figure == 66)
			{
				if (abs(XFigure - XKing) == abs(YFigure - YKing))
				{
					cout << "Yes";
				}
				else
				{
					cout << "No";
				}
			}

			////////////////////////////////////////Knight(N)
			if (Figure == 78)
			{
				if ((XKing == XFigure + 1) && (YKing == YFigure + 2))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure + 2) && (YKing == YFigure + 1))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure + 2) && (YKing == YFigure - 1))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure + 1) && (YKing == YFigure - 2))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure - 1) && (YKing == YFigure - 2))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure - 2) && (YKing == YFigure - 1))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure - 2) && (YKing == YFigure + 1))
				{
					cout << "Yes";
				}
				else if ((XKing == XFigure - 1) && (YKing == YFigure + 2))
				{
					cout << "Yes";
				}
				else
				{
					cout << "No";
				}
			}
		}
	}

	cout << "\n";

	return 0;
}