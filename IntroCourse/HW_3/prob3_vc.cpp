/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3
* @compiler VC
*
*/
#include <iostream>
#include <cstring>

void swapLetter(char arr[], int loops);
void words(char arr[], int loops);

void words(char arr[], int loops)
{
	char buffer[10000];							//buffer to write words
	char deleteBuffer[10000] = "";				//to delete tempor.buffer

	bool differentSymbol = false;				//to find the end of a word
	int counter = 0;							//index of symbols different from letters
	int k = 0;									//index of buffer
	unsigned int length = strlen(arr);

	for (int i = 0; i < length; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))	//beginning of a word
		{
			buffer[k] = arr[i];								//getting word from string
			k++;
			counter++;

			if (((arr[i + 1] >= 'A' && arr[i + 1] <= 'Z') || (arr[i + 1] >= 'a' && arr[i + 1] <= 'z')) == false) //finding end of word
			{
				if ((arr[i+1] == '-' && (i+1) != 0) && (((arr[i+1 - 1] >= 'a' && arr[i+1 - 1] <= 'z') || (arr[i+1 - 1] >= 'A' && arr[i+1 - 1] <= 'Z')) && ((arr[i+1 + 1] >= 'a' && arr[i+1 + 1] <= 'z') || (arr[i+1 + 1] >= 'A' && arr[i+1 + 1] <= 'Z'))))
				{
					buffer[k] = arr[i+1];					//Ana-Maria case solution
					counter++;									
					k++;
					continue;
				}
				else
				{
				differentSymbol = true;						//end of word
				}
			}
		}
		else
		{
			// continue when arr[i] is different from letter
			if (((arr[i] == '-' && (i) != 0) && (((arr[i - 1] >= 'a' && arr[i - 1] <= 'z') || (arr[i - 1] >= 'A' && arr[i - 1] <= 'Z')) && ((arr[i + 1] >= 'a' && arr[i + 1] <= 'z') || (arr[i + 1] >= 'A' && arr[i + 1] <= 'Z'))))==false)
			{			
				std::cout << arr[i]; //print the symbol after current word
			}
		}

		if (differentSymbol)
		{

			buffer[k] = '\0';								//set end of buffer
			if (strlen(buffer) == 1)
			{
				std::cout << buffer;						//in case word consist of a single letter :)
			}
			else 
			{
			swapLetter(buffer,loops);				//doing stuffs with the word in a function
			}

			if ((((arr[i + 1] >= 'A' && arr[i + 1] <= 'Z') || (arr[i + 1] >= 'a' && arr[i + 1] <= 'z')) == false) && arr[i + 1] != '\0')
			{
				//std::cout << arr[counter];		//print the symbol after current word
				counter++;
			}

			strcpy(buffer, deleteBuffer);		//to delete buffer
			k = 0;								//for next loop
			differentSymbol = false;			//for next loop

		}
	}
}

void swapLetter(char arr[], int loops)				//swap first and last
{
	unsigned int length = strlen(arr);
	char tempArr[10001] = "";						//array to store the new word		

	int k = 1;
	for (int i = 0; i < loops; i++)				//...looping
	{
		for (int i = 0; i < length - 1; i++)
		{
			tempArr[0] = arr[length - 1];		//first==last
			tempArr[k] = arr[i];				//moving symbols to the right (Pesh-->o+Pesh)
			k++;
		}
		k = 1;
		for (int i = 0; i < length; i++)
		{
			arr[i] = tempArr[i];				//swapping (Pesho becomes oPesh)
		}
	}

	for (int i = 0; i < length; i++)
	{
		std::cout<<arr[i];
	}
}

int main()
{
	char text[10000];
	int loopNumber;
	char textarr[10000] = "";

	std::cin.getline(text, 10000);
	std::cin >> loopNumber;

	words(text, loopNumber);

	std::cout << "\n";
	return 0;
}