/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 8
* @compiler VC
*
*/

#include <iostream>

void fillArrayOfNumbers(unsigned int howManyNums, int arrOfNums[]);
void sorting(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums);
void sorting2(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums, int counter);
void sorting3(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums, int counter);
int modulo(int number, int divisor);



int modulo(int number, int divisor)												//http://stackoverflow.com/questions/11630321/why-does-c-output-negative-numbers-when-using-modulo
{																				//http://stackoverflow.com/a/23214321
	return ((number %= divisor) < 0) ? number + divisor : number;				//http://stackoverflow.com/a/21470301
}																				//http://stackoverflow.com/a/1082938

void fillArrayOfNumbers(unsigned int howManyNums, int arrOfNums[])
{
	for (int i = 0; i < howManyNums; i++)
	{
		std::cin >> arrOfNums[i];
	}
}


void sorting(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums)
{
	int counter = 0;

	for (int i = 0; i < howManyNums; i++)
	{
		if (modulo(arrOfNums[i], 3) == 0)
		{
			bufferOfNums[counter] = arrOfNums[i];
			counter++;
		}
	}

	sorting2(arrOfNums, bufferOfNums, howManyNums, counter);
}


void sorting2(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums, int counter)
{
	for (int i = 0; i < howManyNums; i++)
	{
		if (modulo(arrOfNums[i], 3) == 1)
		{
			bufferOfNums[counter] = arrOfNums[i];
			counter++;
		}
	}

	sorting3(arrOfNums, bufferOfNums, howManyNums, counter);
}


void sorting3(int arrOfNums[], int bufferOfNums[], unsigned int howManyNums, int counter)
{

	for (int i = 0; i < howManyNums; i++)
	{
		if (modulo(arrOfNums[i], 3) == 2)
		{
			bufferOfNums[counter] = arrOfNums[i];
			counter++;
		}
	}

	for (int i = 0; i < counter; i++)
	{
		std::cout << bufferOfNums[i] << " ";
	}
}


int main()
{
	unsigned int numbers;
	std::cin >> numbers;
	int arrOfNumbers[100000];
	int bufferOfNumbers[100000];

	if (numbers > 0 && numbers < 100000)
	{
		fillArrayOfNumbers(numbers, arrOfNumbers);
		sorting(arrOfNumbers, bufferOfNumbers, numbers);

		std::cout << "\n";
	}

	return 0;
}