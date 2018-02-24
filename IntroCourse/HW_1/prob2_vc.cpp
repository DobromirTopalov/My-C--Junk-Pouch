/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {

	double EGN;
	cin >> EGN;
	double firstDigit, secondDigit, thirdDigit, fourthDigit, fifthDigit, sixthDigit, seventhDigit, eigthDigit, ninthDigit, tenthDigit, tenthDigitSum;
	int year;

	firstDigit = (int)(EGN / 10e+8);
	secondDigit = ((int)(EGN / 10e+7)) % 10;
	thirdDigit = ((int)(EGN / 10e+6)) % 10;
	fourthDigit = ((int)(EGN / 10e+5)) % 10;
	fifthDigit = ((int)(EGN / 10e+4)) % 10;
	sixthDigit = ((int)(EGN / 10e+3)) % 10;
	seventhDigit = ((int)(EGN / 10e+2)) % 10;
	eigthDigit = ((int)(EGN / 10e+1)) % 10;
	ninthDigit = ((int)(EGN / 10)) % 10;
	tenthDigit = ((long long int)EGN % 10);

	tenthDigitSum = ((firstDigit * 2) + (secondDigit * 4) + (thirdDigit * 8) + (fourthDigit * 5) + (fifthDigit * 10) + (sixthDigit * 9) + (seventhDigit * 7) + (eigthDigit * 3) + (ninthDigit * 6));

	if ((int)tenthDigitSum % 11 == tenthDigit)
	{
		if ((thirdDigit == 0 && fourthDigit >= 1 && fourthDigit <= 9) || (thirdDigit == 1 && fourthDigit >= 0 && fourthDigit <= 2)) //from 1900to1999
		{
			year = 1900 + firstDigit * 10 + secondDigit;
			if (thirdDigit == 0 && fourthDigit == 2) //feb check
			{

				if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
				{
					//leap year
					if ((fifthDigit <= 2 && fifthDigit > 0 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else if (year % 4 == 0 && year % 100 == 0)
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
			}

			if (thirdDigit == 0 && fourthDigit == 1)//01
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 3)//03
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 4)//04
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 5)//05
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 6)//06
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 7)//07
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 8)//08
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 0 && fourthDigit == 9)//09
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 1 && fourthDigit == 0)//10
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 1 && fourthDigit == 1)//11
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 1 && fourthDigit == 2)//12
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit << fourthDigit << ".19" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}

			if ((int)ninthDigit % 2 == 0)
			{
				cout << " M \n";
			}
			else
			{
				cout << " F \n";
			}







		}//else{
		 //	cout << "Bad input data!";//is not okay
		 //}

		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if ((thirdDigit == 2 && fourthDigit >= 1 && fourthDigit <= 9) || (thirdDigit == 3 && fourthDigit >= 0 && fourthDigit <= 2)) //pre1900
		{
			year = 1800 + firstDigit * 10 + secondDigit;
			if (thirdDigit == 2 && fourthDigit == 2) //feb check
			{

				if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
				{
					//leap year
					if ((fifthDigit <= 2 && fifthDigit > 0 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else if (year % 4 == 0 && year % 100 == 0)
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
			}


			//if ((thirdDigit == 0 && fourthDigit != 2 && fourthDigit != 0) || (thirdDigit == 1 && fourthDigit <= 2 && fourthDigit >= 0))//check for diff months
			//{
			if (thirdDigit == 2 && fourthDigit == 1)//01
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			//}
			if (thirdDigit == 2 && fourthDigit == 3)//03
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 4)//04
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 5)//05
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 6)//06
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 7)//07
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 8)//08
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 2 && fourthDigit == 9)//09
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 3 && fourthDigit == 0)//10
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 3 && fourthDigit == 1)//11
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 3 && fourthDigit == 2)//12
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 2 << fourthDigit << ".18" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}

			if ((int)ninthDigit % 2 == 0)
			{
				cout << " M \n";
			}
			else
			{
				cout << " F \n";
			}

		}
		//else {
		//	cout << "Bad input data!";//is not okay
		//}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if ((thirdDigit == 4 && fourthDigit >= 1 && fourthDigit <= 9) || (thirdDigit == 5 && fourthDigit >= 0 && fourthDigit <= 2)) //post1999
		{
			year = 2000 + firstDigit * 10 + secondDigit;
			if (thirdDigit == 4 && fourthDigit == 2) //feb check
			{

				if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
				{
					//leap year
					if ((fifthDigit <= 2 && fifthDigit > 0 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else if (year % 4 == 0 && year % 100 == 0)
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
				else
				{
					//common year
					if ((fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 8))
					{
						cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit; //is okay
					}
					else
					{
						cout << "Bad input data!";//is not okay
					}
				}
			}


			//if ((thirdDigit == 0 && fourthDigit != 2 && fourthDigit != 0) || (thirdDigit == 1 && fourthDigit <= 2 && fourthDigit >= 0))//check for diff months
			//{
			if (thirdDigit == 4 && fourthDigit == 1)//01
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			//}
			if (thirdDigit == 4 && fourthDigit == 3)//03
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 4)//04
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 5)//05
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 6)//06
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 7)//07
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 8)//08
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 4 && fourthDigit == 9)//09
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 5 && fourthDigit == 0)//10
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 5 && fourthDigit == 1)//11
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 0) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}
			if (thirdDigit == 5 && fourthDigit == 2)//12
			{
				if ((fifthDigit == 3 && sixthDigit >= 0 && sixthDigit <= 1) || (fifthDigit == 0 && sixthDigit >= 1 && sixthDigit <= 9) || (fifthDigit == 1 && sixthDigit >= 0 && sixthDigit <= 9) || (fifthDigit == 2 && sixthDigit >= 0 && sixthDigit <= 9))
				{
					cout << fifthDigit << sixthDigit << "." << thirdDigit - 4 << fourthDigit << ".20" << firstDigit << secondDigit;//is okay
				}
				else
				{
					cout << "Bad input data!";//is not okay
				}
			}

			if ((int)ninthDigit % 2 == 0)
			{
				cout << " M \n";
			}
			else
			{
				cout << " F \n";
			}







		}
		//else {
		//	cout << "Bad input data!";//is not okay
		//}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	}
	else
	{
		cout << "Bad input data!";//is not okay
	}
	return 0;
}