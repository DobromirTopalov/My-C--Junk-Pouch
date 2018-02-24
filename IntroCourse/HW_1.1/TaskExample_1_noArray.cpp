#include <iostream>
#include <cmath>

int main()
{
	/* input data part */

	int size;
	std::cin >> size;							//get size of the sequence

	if (size > pow(10, 9)) {						//check if input is correct
		std::cout << "no\n";					//print message 
		return 1;								//error
	}


	/* algorithm 'trion checking' part */

	int firstElement, secondElement, thirdElement;			//vars to store first 3 elements from the sequence

	if (size > 2) {
					//we know it is a 'trion' if size < 2, so we check only the important cases  

		bool allOkay = true;
		bool isHigher = false;				 //bool variables to follow what condition is alright when we compare 'element-neighbours'
		bool isLower = false;				 // var <= var >= var
											 // var >= var <= var		  we need one/both to be true,else - its not 'trion'

	 //{	without using dynamic arrays we have to get input and work on it directly,so we do it over and over ...
		for (int i = 0; i < size - 2; i++) {

			if (i == 0) {					//first two inputs must be by the user after this we just swap values 
			
				std::cin >> firstElement >> secondElement;
				if ( abs(firstElement) > pow(10, 6) || abs(secondElement) > pow(10, 6) ) {			//check if input is okay

					std::cout << "no\n";					//print message 
					return 1;								//error
				}
			}

			std::cin >> thirdElement;						//third element is always new by the user, other elements we swap during completion
			if ( abs(thirdElement) > pow(10, 6) ) {			//check if input is okay
			
				std::cout << "no\n";						//print message 
				return 1;									//error
			}

	//}
			if (firstElement <= secondElement && secondElement >= thirdElement) {
			
				isHigher = true;
			}

			if (firstElement >= secondElement && secondElement <= thirdElement) {
			
				isLower = true;
			}

			if (!(isHigher || isLower)) {				//if both conditions fail, abort everything and show result (if we use array)

				allOkay = false;						//without array we store a bool var and change its value so we use it later
			}											//do not abort loop - to simulate filling values in an array
			
			isHigher = false;						//else reset conditions and procceed with next element and its neighbours
			isLower = false;						//if loop runs till the end without any failure - we show a positive result

			firstElement = secondElement;			//swap elements in the sequence
			secondElement = thirdElement;

		}

		if (allOkay) {

			std::cout << "yes\n";
			return 0;
		}
		else {
			std::cout << "no\n";
			return 0;
		}
	}
	else{											//for all the cases: size < 2	
		if (size == 1)								//examples: 1 - [89] , 2 - [10,20] , 0 - [undefined array/empty array]
		{
			std::cin >> firstElement;				//useless but we need it to imitate filling an array
		}
		else if (size == 2)
		{
			std::cin >> firstElement >> secondElement;	//useless but we need it to imitate filling an array
		}
		std::cout << "yes\n";						

	}

	/* ending part */
	//nothing to do here, no memory used - nothing to leak, nothing to show in console

	return 0;
}