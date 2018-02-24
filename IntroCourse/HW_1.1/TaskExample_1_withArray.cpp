#include <iostream>
#include <cmath>

int main()
{
						/* input data part */
	int size;									
	std::cin >> size;							//get size of dynamically allocated array from the user

	if (size > pow(10, 9))						//check if input is correct
	{
		std::cout << "no\n";					//print message 
		return 1;								//error
	}


	int* sequence = new int[size];				//dynamically allocated array with user input size
	//must use delete later

	for (int i = 0; i < size; i++)				//fill array with some elements
	{
		std::cin >> sequence[i];				
	
		if (abs(sequence[i]) > pow(10, 6))			//check if input is okay
		{
			std::cout << "no\n";					//print message 
			return 1;								//error
		}
	}


						/* algorithm 'trion checking' part */
	if (size > 2)						
	{												//we know it is a 'trion' if size < 2, so we check only the important cases  

		bool isHigher = false;						//bool variables to follow what condition is alright when we compare 'element-neighbours'
		bool isLower = false;

		for (int i = 1; i < size - 1; i++)			//start from n+1 and loop to n-1 | first and last elements have only 1 neighbour
		{
			if (sequence[i - 1] <= sequence[i] && sequence[i] >= sequence[i + 1])
			{
				isHigher = true;
			}
			
			if (sequence[i - 1] >= sequence[i] && sequence[i] <= sequence[i + 1])
			{
				isLower = true;
			}

			if ( !(isHigher || isLower) )			//if both conditions fail, abort everything and show result
			{
				std::cout << "no\n";
				return 0;
			}

			isHigher = false;						//else reset conditions and procceed with next element and its neighbours
			isLower = false;						//if loop runs till the end without any failure - we show a positive result

		}

		std::cout << "yes\n";
	}
	else											
	{
		std::cout << "yes\n";						//for all the cases: size < 2
													//examples: 1 - [89] , 2 - [10,20] , 0 - [undefined array/empty array]
	}
						
	
						/* ending part */
	delete sequence;								//release allocated memory - prevent memory leak


	return 0;
}