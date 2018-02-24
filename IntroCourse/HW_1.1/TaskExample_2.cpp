#include <iostream>

int main()
{
						/* input part */

	unsigned int number;					//original value of the number - using it to loop on
	std::cin >> number;
	
	if (number >= 1000000000)				//check if input is alright
	{
		std::cout << "Invalid input!\n";
		return 1;
	}

	int tempNumber = number;				//temp. value of the number - using to cut bit by bit
	int numberToPrint = number;				//copy of the number - working on its bits directly
	int countTheSequence = 0;				//count if there are 0000... or 111....
	int beginningOfBitChange = 1;			//mask variable

						/* algorithm part */

	while (number)												//to loop the bits
	{
		int bit = tempNumber & 1;								//get first bit
		while (bit == (tempNumber & 1))							//count sequence of same bits
		{
			countTheSequence++;									//number of same in a row
			tempNumber >>= 1;									//shifting bits of number a.k.a cut the part that we count
		}

		if (countTheSequence >= 2)								//a sequence is 2 or more same bits
		{
												//mask variable	
			if (countTheSequence % 2 != 0)		//if sequence is 3-5-7-9 then we have to move mask 
				beginningOfBitChange <<= 1;		//mask
			
			if (bit == 1)															//if the first bit is 1
			{
				for (int i = 0; i < countTheSequence / 2; i++)						//loop to n/2 - number of total loops needed to change the bits
				{																	//Examples: 3/2 = 1 | 6/2 = 3 | 7/2 = 3 | 8/2 = 4	
					numberToPrint = numberToPrint & (~(beginningOfBitChange));		//change only the bit we want to change
					beginningOfBitChange <<= 1;										//move mask

					if (countTheSequence % 2 == 0 && countTheSequence > 2)			//move mask one more time if we have a sequence > 2
						beginningOfBitChange <<= 1;					
				}
			}
			else																	//if the first bit is 0
			{
				for (int i = 0; i < countTheSequence / 2; i++)						//same idea
				{
					numberToPrint = numberToPrint ^ ((beginningOfBitChange));		//. . .
					beginningOfBitChange <<= 1;										//. . .

					if (countTheSequence % 2 == 0 && countTheSequence > 2)			//. . .
						beginningOfBitChange <<= 1;									//. . .
				}
			}
		}

		number >>= countTheSequence;			//cut the sequence out of the number we use to loop on
		countTheSequence = 0;					//reset counter to count new sequences
		beginningOfBitChange <<= 1;				//move mask on every iteration
	}

						/* ending part */

	std::cout << numberToPrint << "\n";			//result number

	return 0;
}


