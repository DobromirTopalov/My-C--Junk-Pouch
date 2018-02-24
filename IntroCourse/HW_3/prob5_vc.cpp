/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 5
* @compiler VC
*
*/

#include <iostream>

void numsFromSentence(char arr[], int base);
int stringToValue(char digit);
unsigned long int anythingToDecimal(char arr[], int base);
unsigned long int sumOfDecimalNumbers(unsigned long int firstDecimal, unsigned long int secondDecimal);
void cutBuffer(char buffer[], int base);
int getBase(char buffer[], int base);


void numsFromSentence(char arr[],int base)
{
	char buffer[1000];							//buffer to write on
	char deleteBuffer[1000] = "";				//to delete tempor.buffer
	int theBase = 0;

	bool differentSymbol = false;				//to find the end of a word or number
	int counter = 0;							//index of symbols different from letters or numbers
	int k = 0;									//index of buffer
	int j = 0;									//index of the beginning of the new string without prefixes
	
	unsigned long int firstDecimal=0;
	unsigned long int secondDecimal = 0;						//using it for sum function
	unsigned long int result = 0;								//final result
	int length = strlen(arr);

	for (int i = 0; i < length; i++)
	{
		if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= '0' && arr[i] <= '9') || (arr[i] >= 'a' && arr[i] <= 'z'))	//beginning of a word or number
		{
			buffer[k] = arr[i];
			k++;
			counter++;

			if (((arr[i+1] >= 'A' && arr[i+1] <= 'Z') || (arr[i+1] >= '0' && arr[i+1] <= '9') || (arr[i+1] >= 'a' && arr[i+1] <= 'z'))==false) //finding end of word
			{
				differentSymbol = true;
			}
		}
		else
		{
			//continue when arr[i] is different from letter								//does nothing lol
			//std::cout << arr[i]; //print the symbol after current word						
		}

		if (differentSymbol)
		{

			buffer[k] = '\0';								//set end of buffer
			theBase=getBase(buffer, base);					//write base somewhere before next function

			cutBuffer(buffer,base);							//removing prefix from number

			anythingToDecimal(buffer, getBase(buffer, base));				//doing stuffs with the word or number in a function
			
			firstDecimal=anythingToDecimal(buffer,theBase);					//current and next function - find result
			result += sumOfDecimalNumbers(firstDecimal, secondDecimal);

			if ((((arr[i + 1] >= 'A' && arr[i + 1] <= 'Z') || (arr[i + 1] >= 'a' && arr[i + 1] <= 'z')) == false) && arr[i + 1] != '\0')
			{
				//std::cout << arr[counter];		//print the symbol after current word
				counter++;							//need it for skipping spaces and + and ...blah blah bla 
			}

			strcpy(buffer, deleteBuffer);		//to delete buffer
			k = 0;								//for next loop
			differentSymbol = false;			//for next loop

		}
	}
	std::cout << result;
	std::cout << "\n";							//new line because of satan!
}

void cutBuffer(char buffer[],int base)			//remove prefix from numbers/string
{
	int bufferLength = strlen(buffer);
	
	int j = 0;									//tempor. variable/index of new loop
	int round = 0;								//tempor. variable for index later
	char buffer2[1000];							//tempor. array to swap the new with the old string
	
	if (buffer[0] == '0' && buffer[0 + 1] == 'b')
	{
		base = 2;
		j += 2;
	}
	else if (buffer[0] =='0' && (buffer[1] >='0' && buffer[1]<='9'))
	{
		base = 8;
		j += 1;
	}
	else if (buffer[0] !='0')
	{
		base = 10;
		j += 0;
	}
	else if (buffer[0] == '0' && buffer[0 + 1] == 'x')
	{
		base = 16;
		j += 2;
	}

	for (round; j < bufferLength; round++)		//write on tempor. array
	{
		buffer2[round] = buffer[j];
		j++;
	}
	buffer2[round] = '\0';						//end of array
	strcpy(buffer,"");							//delete old one

	for (int i=0; i <= strlen(buffer2); i++)	//swap tempor. array with old one
	{
		buffer[i] = buffer2[i];
	}

}

int getBase(char buffer[], int base)			//base
{

	if (buffer[0] == '0' && buffer[0 + 1] == 'b')
	{
		base = 2;
	}
	else if (buffer[0] == '0' && (buffer[1] >= '0' && buffer[1] <= '9'))
	{
		base = 8;
	}
	else if (buffer[0] != '0')
	{
		base = 10;
	}
	else if (buffer[0] == '0' && buffer[0 + 1] == 'x')
	{
		base = 16;
	}
	return base;
}

int stringToValue(char digit)						//converting a text to number
{
	if (digit >= '0' && digit <= '9')
	{
		return (int)digit - '0';					//digit to int
	}
	else
	{
		return (int)digit - 'A' + 10;				//letter to int
	}
}

unsigned long int anythingToDecimal(char arr[], int base)
{
	int length = strlen(arr);
	unsigned long int power = 1;									//base^0(power=1)......base^1.....base^2....base^3....
	unsigned long int result = 0;									//number in decimal

	for (int i = length - 1; i >= 0; i--)			//length-1 ,convert from right to left while changing the power of base by 1 
	{
		if (stringToValue(arr[i]) >= base)
		{
			return 0;								//if this statement is true,the number we use is not a valid number.-number must be less than its base
		}

		result += stringToValue(arr[i]) * power;
		power = power * base;
	}

	return result;
}

unsigned long int sumOfDecimalNumbers(unsigned long int firstDecimal, unsigned long int secondDecimal)	//TOTAL DMG
{
	unsigned long int sum;
	sum = firstDecimal + secondDecimal;
	return sum;
}

int main()
{
	char statement[1000];
	std::cin.getline(statement, 1000);
	int base=0;
	

	numsFromSentence(statement,base);
	return 0;
}