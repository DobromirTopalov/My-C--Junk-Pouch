/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 7
* @compiler VC
*
*/

#include <iostream>
#include <cstring>

void appendWords(char arr[], char arr2[]);
void wordToLanguage(char arr[], char consonantword[], char vowelword[]);
void wordsFromSentence(char arr[], char consonantword[], char vowelword[]);

void wordsFromSentence(char arr[],char consonantword[], char vowelword[])
{
	char buffer[10000];							//buffer to write words
	char deleteBuffer[10000]="";				//to delete tempor.buffer

	bool differentSymbol = false;				//to find the end of a word
	int counter = 0;							//index of symbols different from letters
	int k = 0;									//index of buffer
	unsigned int length = strlen(arr);			

	for (int i = 0; i < length; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z'))	//beginning of a word
		{
			buffer[k] = arr[i];
			k++;
			counter++;
			
			if (((arr[i+1] >= 'A' && arr[i+1] <= 'Z') || (arr[i+1] >= 'a' && arr[i+1] <= 'z')) == false) //finding end of word
			{
				differentSymbol = true;
			}
		}
		else
		{
			// continue when arr[i] is different from letter

			std::cout << arr[i]; //print the symbol after current word
		}
		
		if (differentSymbol)
		{

			buffer[k] = '\0';								//set end of buffer
			wordToLanguage(buffer, consonantword, vowelword);				//doing stuffs with the word in a function

			if ((((arr[i + 1] >= 'A' && arr[i + 1] <= 'Z') || (arr[i + 1] >= 'a' && arr[i + 1] <= 'z')) == false)&&arr[i+1]!='\0')
			{
				//std::cout << arr[counter];		//print the symbol after current word
				counter++;
			}

			strcpy(buffer,deleteBuffer);		//to delete buffer
			k = 0;								//for next loop
			differentSymbol = false;			//for next loop

		}
	}
}

void wordToLanguage(char arr[], char consonantword[], char vowelword[])
{
	unsigned int length = strlen(arr);
	bool firstIsBig = false;
	bool firstTwoLet = false;
	bool vowel = false;
	int counter = 0;
	int counter2 = 0;

	char temp[10000];
	char temp2[10000];

	if ((arr[0] == 'a') || (arr[0] == 'e') || (arr[0] == 'i') || (arr[0] == 'o') || (arr[0] == 'u')           //Omeletway,OMELETWAY,omeletway
		|| (arr[0] == 'A') || (arr[0] == 'E') || (arr[0] == 'I') || (arr[0] == 'O') || (arr[0] == 'U'))		
	{
		appendWords(arr, vowelword);
		if ((arr[0] >= 'A' && arr[0] <= 'Z')&& (arr[1] >= 'A' && arr[1] <= 'Z'))
		{
			length = strlen(arr);
			for (int i = 0; i<length; i++)
			{
				if (arr[i]>='a' && arr[i]<='z')
				{
					arr[i] = arr[i] - 32;
				}
			}
		}
	}
	
	else																										//Ananabay,ANANABAY,ananabay
	{
		if ((arr[0] >= 'A' && arr[0] <= 'Z') && (arr[1] >= 'A' && arr[1] <= 'Z'))
		{
			firstTwoLet = true;				//All letters to big ones
		}

		for (int i = 0; i<length; i++)
		{
			if ((arr[i] == 'a') || (arr[i] == 'e') || (arr[i] == 'i') || (arr[i] == 'o') || (arr[i] == 'u')
				|| (arr[i] == 'A') || (arr[i] == 'E') || (arr[i] == 'I') || (arr[i] == 'O') || (arr[i] == 'U'))
			{

				counter = i;
				vowel = true;				//vowel-found!
				break;
			}
			else
			{
				if ((arr[i] >= 'A' && arr[i] <= 'Z') && (arr[i+1] >= 'a' && arr[i+1] <= 'z'))
				{
					if ((arr[i] >= 'A' && arr[i] <= 'Z'))
					{
						firstIsBig = true;                                // if capital at start -> capital in new word
						arr[i] = arr[i] + 32;
						temp2[i] = arr[i];
						temp2[i + 1] = '\0';
					}
				}
				else
				{
					temp2[i] = arr[i];
					temp2[i+1] ='\0';
				}
			}
		}

		if (vowel)
		{
			if (firstIsBig)
			{
				temp[0] = arr[counter] - 32;
				counter++;
				for (int i = 1; i < length - 0; i++)	//-1
				{
					temp[i] = arr[counter];
					counter++;
					temp[counter + 0] = '\0';			//+1
				}
			}
			else
			{
				for (int i = 0; i < length - 0; i++)	//-1
				{
					temp[i] = arr[counter];
					counter++;
					temp[counter + 0] = '\0';			//+1
				}
			}
		}

		appendWords(temp,temp2);
		appendWords(temp,consonantword);
		for (int i = 0; i < strlen(temp); i++)
		{
			arr[i] = temp[i];
			arr[strlen(temp)] = '\0';
		}
		

		if (firstTwoLet)   //All letters to big ones
		{
			length = strlen(arr);
			for (int i = 0; i<length; i++)
			{
				if (arr[i] >= 'a' && arr[i] <= 'z')
				{
					arr[i] = arr[i] - 32;
				}
			}
		}
	}
	
	for (int i = 0; i < strlen(arr); i++)
	{
		std::cout << arr[i];
	}

}

void appendWords(char arr[], char arr2[])
{
	unsigned int length = strlen(arr);
	unsigned int length2 = strlen(arr2);
	unsigned int totalLength = length + length2;

	int temp = length;
	for (int i=0; i < length2;i++)
	{
		if (temp < totalLength)
		{
			arr[temp] = arr2[i];
		}
		temp++;
	}
	arr[totalLength] = '\0';
}

int main() 
{
	char sentence[10000];

	char consonantword[3] = "ay";
	char vowelword[4] = "way";

	std::cin.getline(sentence, 10000);

	//wordToLanguage(sentence, consonantword, vowelword);
	wordsFromSentence(sentence, consonantword, vowelword);

	std::cout << "\n";
	return 0;
}