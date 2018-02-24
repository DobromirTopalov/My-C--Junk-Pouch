/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 2B
* @compiler VC
*
*/

#include "UI.hpp"
#include <iostream>
#include <math.h>

double* findPointOfIntersection (double** buffer, const double beam_X1, const double beam_Y1, const double beam_X2, const double beam_Y2, const double object_X1, const double object_Y1, const double object_X2, const double object_Y2);
bool isPointOnSegment (const double* buffer, const double& object_X1, const double& object_Y1, const double& object_X2, const double& object_Y2); 
double* findPointOfIntersectOnCircle (double** buffer,bool& isOnTarget, const double* point, const double& startX, const double& startY, const double& target_X, const double& target_Y, const double& target_R);
double* reflectedPoint (double **buffer, const double& pointOnObject_X, const double& pointOnObject_Y, const double& object_X1, const double& object_Y1, const double& object_X2, const double& object_Y2, const double& pointToReflect_X, const double& pointToReflect_Y);

int main()
{

	//		data declarations
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	double input[1000];
		
	unsigned int numberOfRounds = 1;						//temporary
	unsigned int counter = 1;
	bool isHit = false;

	double* point = new double[2];
	double* nextPoint = new double[2];
	double* pointOnTheTarget = new double[2];

	do {
		std::cout << "This is round: #["<< counter <<"] ! \n";
		GetInput(input);

		double wallCoordinates[16];
		{
			//top wall
			wallCoordinates[0] = 1;
			wallCoordinates[1] = 1;
			wallCoordinates[2] = input[0];
			wallCoordinates[3] = 1;
				SetRaySegment(0, 0, input[0], 0);
				SetRaySegment(1, 1, input[0], 1);
			//bottom wall
			wallCoordinates[4] = 1;
			wallCoordinates[5] = input[1]-28;
			wallCoordinates[6] = input[0];
			wallCoordinates[7] = input[1]-28;
				SetRaySegment(0,input[1]-28,input[0],input[1]-28);
				SetRaySegment(1, input[1] - 29, input[0], input[1] - 29);
			//left wall
			wallCoordinates[8] = 1;
			wallCoordinates[9] = 1;
			wallCoordinates[10] = 1;
			wallCoordinates[11] = input[1];
				SetRaySegment(0, 0, 0, input[1]);
				SetRaySegment(1, 1, 1, input[1]);
			//right wall
			wallCoordinates[12] = input[0]-7;
			wallCoordinates[13] = 1;
			wallCoordinates[14] = input[0]-7;
			wallCoordinates[15] = input[1];
				SetRaySegment(input[0]-7, 0, input[0]-7, input[1]);
				SetRaySegment(input[0] - 8, 1, input[0] - 8, input[1]);
		}	//drawing the field


		double target_X = input[2];
		double target_Y = input[3];
		double target_R = input[4];

		double beginningPoint_X = input[5];
		double beginningPoint_Y = input[6];
		double direction_X = input[7];
		double direction_Y = input[8];

		int maxReflections = (unsigned int)input[9];
		unsigned int maxMirrorsInRoom = (unsigned int)input[10];
		unsigned int maxInputSize = 11 + 4 * maxMirrorsInRoom - 1;
		
	
		
	//		start of logic
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

		double range_X;
		double range_Y;
		double* closestPoint = new double[2];
		double* currentClosestPoint = new double[2];
		
		while (maxReflections >= 0)
		{
			closestPoint[0] = closestPoint[1] = -1000;
			bool isAnyMirrorHit = false;
			bool isAnyWallHit = false;
			bool isTargetBOOM = false;
			int indexOfCloseObject = 0;
			
			if (beginningPoint_X > direction_X) //left
			{
				range_X = beginningPoint_X;
				range_Y = beginningPoint_Y;

				indexOfCloseObject = 0;
				for (int i = 11; i <= maxInputSize; i += 4)
				{
					point = findPointOfIntersection(&point, beginningPoint_X, beginningPoint_Y, direction_X, direction_Y, input[i], input[i + 1], input[i + 2], input[i + 3]);
					bool isOnMirror = isPointOnSegment(point, input[i], input[i + 1], input[i + 2], input[i + 3]);
					
					if (isOnMirror)
					{
						pointOnTheTarget = findPointOfIntersectOnCircle(&pointOnTheTarget, isHit, point, beginningPoint_X, beginningPoint_Y, target_X, target_Y, target_R);
						if (isHit)
						{
							isTargetBOOM = true;
						}
	
						if (point[0] < range_X)
						{
							currentClosestPoint[0] = point[0];
							currentClosestPoint[1] = point[1];
							isAnyMirrorHit = true;
						}

						if (currentClosestPoint[0] > closestPoint[0])
						{
							indexOfCloseObject = i;
							closestPoint[0] = currentClosestPoint[0];
							closestPoint[1] = currentClosestPoint[1];
						}
					}					
				}

				if (isAnyMirrorHit)
				{
					if (isTargetBOOM && (pointOnTheTarget[0] > closestPoint[0]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, pointOnTheTarget[0], pointOnTheTarget[1]);
						std::cout << "Congratulations!You've hit the target!\n";
						return 0;
					}
					if (isPointOnSegment(closestPoint, input[indexOfCloseObject], input[indexOfCloseObject + 1], input[indexOfCloseObject + 2], input[indexOfCloseObject + 3]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, closestPoint[0], closestPoint[1]);
						nextPoint = reflectedPoint(&nextPoint, closestPoint[0], closestPoint[1], input[indexOfCloseObject], input[indexOfCloseObject + 1], input[indexOfCloseObject + 2], input[indexOfCloseObject + 3], beginningPoint_X, beginningPoint_Y);
						
						beginningPoint_X = closestPoint[0];
						beginningPoint_Y = closestPoint[1];
						direction_X = nextPoint[0];
						direction_Y = nextPoint[1];
						maxReflections--;
						continue;
					}
					else
					{
						//std::cout << "Left + Mirror | ";
						//std::cout << "X " << beginningPoint_X << " Y " << beginningPoint_Y << "\n";
						//std::cout << "RX " << direction_X << " RY " << direction_Y << "\n";
						//break;
					}
				}
				else
				{
					indexOfCloseObject = 0;
					for (int i = 0; i < 16; i += 4)
					{
						point = findPointOfIntersection(&point, beginningPoint_X, beginningPoint_Y, direction_X, direction_Y, wallCoordinates[i], wallCoordinates[i + 1], wallCoordinates[i + 2], wallCoordinates[i + 3]);
						bool isOnWall = isPointOnSegment(point, wallCoordinates[i], wallCoordinates[i + 1], wallCoordinates[i + 2], wallCoordinates[i + 3]);
						if (isOnWall)
						{
							pointOnTheTarget = findPointOfIntersectOnCircle(&pointOnTheTarget, isHit, point, beginningPoint_X, beginningPoint_Y, target_X, target_Y, target_R);
							if (isHit)
							{
								isTargetBOOM = true;
							}

							if (point[0] < range_X && point[1] != range_Y)
							{
								currentClosestPoint[0] = point[0];
								currentClosestPoint[1] = point[1];
								isAnyWallHit = true;
								indexOfCloseObject = i;
							}

							if (currentClosestPoint[0] > closestPoint[0] && isAnyWallHit == true)
							{
								indexOfCloseObject = i;
								closestPoint[0] = currentClosestPoint[0];
								closestPoint[1] = currentClosestPoint[1];
							}
						}
					}

					if (isAnyWallHit)
					{

						if (isTargetBOOM && (pointOnTheTarget[0] > closestPoint[0]))
						{
							SetRaySegment(beginningPoint_X, beginningPoint_Y, pointOnTheTarget[0], pointOnTheTarget[1]);
							std::cout << "Congratulations!You've hit the target!\n";
							return 0;
						}


						if (isPointOnSegment(closestPoint, wallCoordinates[indexOfCloseObject], wallCoordinates[indexOfCloseObject + 1], wallCoordinates[indexOfCloseObject + 2], wallCoordinates[indexOfCloseObject + 3]))
						{
							SetRaySegment(beginningPoint_X, beginningPoint_Y, closestPoint[0], closestPoint[1]);
							nextPoint = reflectedPoint(&nextPoint, closestPoint[0], closestPoint[1], wallCoordinates[indexOfCloseObject], wallCoordinates[indexOfCloseObject + 1], wallCoordinates[indexOfCloseObject + 2], wallCoordinates[indexOfCloseObject + 3], beginningPoint_X, beginningPoint_Y);

							beginningPoint_X = closestPoint[0];
							beginningPoint_Y = closestPoint[1];
							direction_X = nextPoint[0];
							direction_Y = nextPoint[1];

							maxReflections--;
							continue;
						}
						else
						{
							//std::cout << "Left + Wall | ";
							//std::cout << "X " << beginningPoint_X << " Y " << beginningPoint_Y << "\n";
							//std::cout << "RX " << direction_X << " RY " << direction_Y << "\n";
							//break;
						}
					}
				}
			}

			if (beginningPoint_X < direction_X) //right
			{
				closestPoint[0] = 100000;
				closestPoint[1] = 100000;

				range_X = beginningPoint_X;
				range_Y = beginningPoint_Y;
				
				indexOfCloseObject = 0;
				for (int i = 11; i <= maxInputSize; i += 4)
				{
					point = findPointOfIntersection(&point, beginningPoint_X, beginningPoint_Y, direction_X, direction_Y, input[i], input[i + 1], input[i + 2], input[i + 3]);
					bool isOnMirror = isPointOnSegment(point, input[i], input[i + 1], input[i + 2], input[i + 3]);
					if (isOnMirror)
					{	
						pointOnTheTarget = findPointOfIntersectOnCircle(&pointOnTheTarget, isHit, point, beginningPoint_X, beginningPoint_Y, target_X, target_Y, target_R);
						if (isHit)
						{
							isTargetBOOM = true;
						}

						if (point[0] > range_X)
						{
							currentClosestPoint[0] = point[0];
							currentClosestPoint[1] = point[1];
							isAnyMirrorHit = true;
						}
						
						if (currentClosestPoint[0] < closestPoint[0] && isAnyMirrorHit == true)
						{
							indexOfCloseObject = i;
							closestPoint[0] = currentClosestPoint[0];
							closestPoint[1] = currentClosestPoint[1];
						}
					}
				}

				if (isAnyMirrorHit)
				{
					if (isTargetBOOM && (pointOnTheTarget[0] < closestPoint[0]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, pointOnTheTarget[0], pointOnTheTarget[1]);
						std::cout << "Congratulations!You've hit the target!\n";
						return 0;
					}

					if (isPointOnSegment(closestPoint, input[indexOfCloseObject], input[indexOfCloseObject + 1], input[indexOfCloseObject + 2], input[indexOfCloseObject + 3]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, closestPoint[0], closestPoint[1]);
						nextPoint = reflectedPoint(&nextPoint, closestPoint[0], closestPoint[1], input[indexOfCloseObject], input[indexOfCloseObject + 1], input[indexOfCloseObject + 2], input[indexOfCloseObject + 3], beginningPoint_X, beginningPoint_Y);
					
						beginningPoint_X = closestPoint[0];
						beginningPoint_Y = closestPoint[1];
						direction_X = nextPoint[0];
						direction_Y = nextPoint[1];
						
						maxReflections--;
						continue;
					}
					else
					{
						//std::cout << "Right + Mirror | ";
						//std::cout << "X " << beginningPoint_X << " Y " << beginningPoint_Y << "\n";
						//std::cout << "RX " << direction_X << " RY " << direction_Y << "\n";
						//break;
					}
				}

				indexOfCloseObject = 0;
				for (int i = 0; i < 16; i += 4)
				{
					point = findPointOfIntersection(&point, beginningPoint_X, beginningPoint_Y, direction_X, direction_Y, wallCoordinates[i], wallCoordinates[i + 1], wallCoordinates[i + 2], wallCoordinates[i + 3]);
					bool isOnWall = isPointOnSegment(point, wallCoordinates[i], wallCoordinates[i + 1], wallCoordinates[i + 2], wallCoordinates[i + 3]);
					if (isOnWall)
					{
						pointOnTheTarget = findPointOfIntersectOnCircle(&pointOnTheTarget, isHit, point, beginningPoint_X, beginningPoint_Y, target_X, target_Y, target_R);
						if (isHit)
						{
							isTargetBOOM = true;
						}

						if (point[0] > range_X && point[1] != range_Y)
						{
							currentClosestPoint[0] = point[0];
							currentClosestPoint[1] = point[1];
							isAnyWallHit = true;
						}
						
						if (currentClosestPoint[0] < closestPoint[0] && isAnyWallHit == true)
						{
							indexOfCloseObject = i;
							closestPoint[0] = currentClosestPoint[0];
							closestPoint[1] = currentClosestPoint[1];
						}
					}
				}

				if (isAnyWallHit)
				{
					if (isTargetBOOM && (pointOnTheTarget[0] < closestPoint[0]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, pointOnTheTarget[0], pointOnTheTarget[1]);
						std::cout << "Congratulations!You've hit the target!\n";
						return 0;
					}

					if (isPointOnSegment(closestPoint, wallCoordinates[indexOfCloseObject], wallCoordinates[indexOfCloseObject + 1], wallCoordinates[indexOfCloseObject + 2], wallCoordinates[indexOfCloseObject + 3]))
					{
						SetRaySegment(beginningPoint_X, beginningPoint_Y, closestPoint[0], closestPoint[1]);
						nextPoint = reflectedPoint(&nextPoint, closestPoint[0], closestPoint[1], wallCoordinates[indexOfCloseObject], wallCoordinates[indexOfCloseObject + 1], wallCoordinates[indexOfCloseObject + 2], wallCoordinates[indexOfCloseObject + 3], beginningPoint_X, beginningPoint_Y);
					
						beginningPoint_X = closestPoint[0];
						beginningPoint_Y = closestPoint[1];
						direction_X = nextPoint[0];
						direction_Y = nextPoint[1];
						
						maxReflections--;
						continue;
					}
					else
					{
						//std::cout << "Right + Wall | ";
						//std::cout << "X " << beginningPoint_X << " Y " << beginningPoint_Y << "\n";
						//std::cout << "RX " << direction_X << " RY " << direction_Y << "\n";
						//break;
					}
				}
			}

			if (beginningPoint_X == direction_X)
			{
				std::cout << "Reflections left: " << maxReflections << " Target survived: " << std::boolalpha << !isHit << "\n";
				std::cout << "90 degree reflection!Shut down application!\n";
				return 0;
			}
		}

		//end internal loop
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		if (maxReflections <= 0)
		{
			std::cout << "\nYou failed to hit the target in the required number of reflections!\nHere is a new game to try again\n";
			//some commands to prompt user if he wants another try ...
			// ...
		}


		delete[] closestPoint;
		delete[] currentClosestPoint;
	
		counter++;
		isHit = false;

	} while (counter <= numberOfRounds);

	delete[] point;
	delete[] nextPoint;
	delete[] pointOnTheTarget;

    return 0;
}


//in *buffer we store the coordinates of the point where two lines intersect
//beam_X and beam_Y are variables for the first line
//object_X and object_Y are variables for the second line
double* findPointOfIntersection (double** buffer, const double beam_X1, const double beam_Y1, const double beam_X2, const double beam_Y2, const double object_X1, const double object_Y1, const double object_X2, const double object_Y2)
{
	// beam line >> a1x + b1y = c1
	double a1 = beam_Y2 - beam_Y1;
	double b1 = beam_X1 - beam_X2;
	double c1 = a1*(beam_X1)+b1*(beam_Y1);

	// object line >> a2x + b2y = c2
	double a2 = object_Y2 - object_Y1;
	double b2 = object_X1 - object_X2;
	double c2 = a2*(object_X1)+b2*(object_Y1);

	double determinant = a1*b2 - a2*b1;

	if (determinant == 0)
	{
		//lines are parallel.
		(*buffer)[0] = -10000;			//value that will always be outside the field
		(*buffer)[1] = -10000;			//value that will always be outside the field

		return *buffer;
	}
	else
	{
		double x = (b2*c1 - b1*c2) / determinant;
		double y = (a1*c2 - a2*c1) / determinant;
		
		(*buffer)[0] = x;
		(*buffer)[1] = y;

		return *buffer;
	}
}

//function to check if the point of intersection is between points of the mirror or wall 
bool isPointOnSegment (const double* buffer, const double& object_X1, const double& object_Y1, const double& object_X2, const double& object_Y2)
{
	double minX = fmin(object_X1, object_X2);
	double maxX = fmax(object_X1, object_X2);
	double minY = fmin(object_Y1, object_Y2);
	double maxY = fmax(object_Y1, object_Y2);

	double EPSILON = 0.00001;
	if (((minX < buffer[0] && buffer[0] < maxX) || fabs(minX - buffer[0]) < EPSILON || fabs(maxX - buffer[0]) < EPSILON) &&
	    ((minY < buffer[1] && buffer[1] < maxY) || fabs(minY - buffer[1]) < EPSILON || fabs(maxY - buffer[1]) < EPSILON))
	{
		return true;
	}

	return false;
}

//same as findPointOfIntersection plan - *buffer holds the point
//+ that it also changes isOnTarget value and this way we sort of returning more than a single information
double* findPointOfIntersectOnCircle (double** buffer, bool& isOnTarget, const double* point, const double& startX, const double& startY, const double& target_X, const double& target_Y, const double& target_R)
{
	double distanceStartEnd = sqrt(pow(point[0] - startX, 2) + pow(point[1] - startY, 2));
	double directionVector_X = (point[0] - startX) / distanceStartEnd;
	double directionVector_Y = (point[1] - startY) / distanceStartEnd;
	
	double T = (directionVector_X * (target_X - startX)) + (directionVector_Y * (target_Y - startY));

	double closestPointToCenter_X = (T*directionVector_X) + startX;
	double closestPointToCenter_Y = (T*directionVector_Y) + startY;

	double distanceCenterClosePoint = sqrt(pow(closestPointToCenter_X - target_X, 2) + pow(closestPointToCenter_Y - target_Y, 2));


	double first_X, first_Y, second_X, second_Y;

	if (distanceCenterClosePoint < target_R)
	{
		isOnTarget = true;						//returns true if hit
		double distTtoIntersectPoint = sqrt(pow(target_R, 2) - pow(distanceCenterClosePoint, 2));

		//first intersection point is:
		first_X = ((T - distTtoIntersectPoint)*directionVector_X) + startX;
		first_Y = ((T - distTtoIntersectPoint)*directionVector_Y) + startY;

		//second intersection point is:
		second_X = ((T + distTtoIntersectPoint)*directionVector_X) + startX;
		second_Y = ((T + distTtoIntersectPoint)*directionVector_Y) + startY;

		double distanceBetweenStartAndFirst = sqrt(pow(first_X - startX, 2) + pow(first_Y - startY, 2));
		double distanceBetweenStartAndSecond = sqrt(pow(second_X - startX, 2) + pow(second_Y - startY, 2));

		//return first point
		if (distanceBetweenStartAndFirst < distanceBetweenStartAndSecond)
		{
			(*buffer)[0] = first_X;
			(*buffer)[1] = first_Y;
			return *buffer;
		}	//return second point
		else if (distanceBetweenStartAndFirst > distanceBetweenStartAndSecond)
		{
			(*buffer)[0] = second_X;
			(*buffer)[1] = second_Y;
			return *buffer;
		}

	}	//return the point that is on the line of the circle and closest to its center
	else if (distanceCenterClosePoint == target_R)
	{
		isOnTarget = true;				//retursn true if hit

		(*buffer)[0] = closestPointToCenter_X;
		(*buffer)[1] = closestPointToCenter_Y;
		return *buffer;
	}	//return the buffer unchanged, tho we never enter this case anyway ...
	else
	{
		return *buffer;
	}

}

//find the point that is a reflection of the start point of the line that hits the wall/mirror
double* reflectedPoint (double **buffer,const double& pointOnObject_X, const double& pointOnObject_Y, const double& object_X1, const double& object_Y1, const double& object_X2, const double& object_Y2, const double& pointToReflect_X, const double& pointToReflect_Y)
{
	bool change = false;
	if (!(object_X2 - object_X1))					//check for deletion by 0 before initializing M1
	{
		//std::cout << "Fail_1\n";
		//after debugging I found out this block does nothing,but will keep it here
		//return *buffer;
	}
	double M1 = (object_Y2 - object_Y1) / (object_X2 - object_X1);		//needed for equation of the line
	
	double M2;
	if (!(M1))								//check for deletion by 0 before init M2
	{
		//std::cout << "Fail_2\n";
		//after debugging I found out this block better not return *buffer and instead M2 = 0
		//return *buffer;
		M2 = 0;
	}
	else
	{
		M2 = (-1 / M1);									// needed for equation of the line
		change = true;
	}

	double B = M2*(-pointOnObject_X) + pointOnObject_Y;		// needed for equation of the line

	double temp_Y = 4;
	double temp_X = temp_Y - B / M2;
		
	if (M2==0)
	{
		if (temp_X == -INFINITY)
		{
			temp_X = pointOnObject_X;
			temp_Y = pointOnObject_Y + 2;
		}
		else if (temp_X == INFINITY || temp_X == -INFINITY)
		{
			temp_X = pointOnObject_X + 2;
			temp_Y = pointOnObject_Y;
		}
	}
	

	//second perpendicular idea, similar idea
	double * midPoint = new double[2];

	double mM1 = M2;
	double mM2;
	
	if (!(mM1))								//check for deletion by 0 before init M2
	{
		//std::cout << "Fail_2.2\n";
		//after debugging I found out this block better not return *buffer and instead M2 = 0
		//return *buffer;
	
		mM2 = 0;
	}
	else
	{
		mM2 = (-1 / mM1);									// needed for equation of the line
	}
	double bB = mM2*(-pointToReflect_X) + pointToReflect_Y;		// needed for equation of the line

	double temp_yY = 4;
	double temp_xX = temp_yY - bB / mM2;
		
	
	if (mM2 == 0)
	{
		if (change == false)
		{
			temp_xX = pointToReflect_X+2;
			temp_yY = pointToReflect_Y + 0;
		}
		else if (change == true)
		{
			temp_xX = pointToReflect_X;
			temp_yY = pointToReflect_Y + 2;
		}
	
		/*			debugging stuff ...
		if (temp_xX == -INFINITY)
		{
			temp_xX = pointToReflect_X;
			temp_yY = pointToReflect_Y + 2;
		}
		else if (temp_xX == INFINITY || temp_xX == -INFINITY)
		{
			temp_xX = pointToReflect_X + 2;
			temp_yY = pointToReflect_Y;
		}
		*/
	}
	

	midPoint = findPointOfIntersection(&midPoint, pointToReflect_X, pointToReflect_Y, temp_xX, temp_yY, pointOnObject_X, pointOnObject_Y, temp_X, temp_Y);

	//......................................................................

	double X = midPoint[0] * 2 - pointToReflect_X;
	double Y = midPoint[1] * 2 - pointToReflect_Y;

	(*buffer)[0] = X;
	(*buffer)[1] = Y;

	delete[] midPoint;

	return *buffer;
}
































/*


		//Въображение + тъпизми
		//папка аутизъм
		//Студентски живот, ах сладък живот
		//липса на морал
		//недостиг на начални 7 год.
		//
		//хахааааа недей са напряга заради тоя код
		//
		//
		//		
		//												  FMI FMI FMI FMI FMI FMI					I LOVE YOU
		//												FMI	FMI FMI FMI FMI FMI FMI						<3
		//	
													//			 HEREE
													//			  HEREEE
													//			   HEREEE
													//			   HEREEEE
													//			    HEREEE	
													//			    HERE	
													//			    HERE	
													//				HERE	
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//				HERE
													//			...,HERE.
													//		   CODE,HEREE
													//	  CODE,ODE,HERE DE
													// CODE,CODE,ODE CODE EE
													//  CODE,CODE,CODE,CODE,EE
													//	  CODE,CODE,CODE,CODE 
//
//
//


*/