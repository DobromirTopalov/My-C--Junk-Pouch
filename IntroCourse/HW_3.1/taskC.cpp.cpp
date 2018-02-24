/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3C
* @compiler VC
*
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstring>

unsigned int getRandomIndex(int min, int max)
{
	int range = (max - 1) - min + 1;
	int randomNum = rand() % range + min;

	return randomNum;
}

char* getRandomWord(char** category, int size)
{
	int randomIndex = getRandomIndex(0, size);
	return category[randomIndex];
}

char* getEmotional() 
{
	int numberOfSigns = getRandomIndex(3, 11);
	char* emotion = new char[numberOfSigns + 1];

	for (int j = 0; j < numberOfSigns; j++) 
	{
		emotion[j] = '!';
	}
	emotion[numberOfSigns] = '\0';
	return emotion;
}


int main()
{
	unsigned int numberOfHeadings = 0;
	std::cout << "Enter number of headings: ";
	std::cin >> numberOfHeadings;
	
	// възклицания
	unsigned int numberOfExpressions = 3;
	char** expressions = new char*[numberOfExpressions];
		expressions[0] = "Shok";
		expressions[1] = "Skandal";
		expressions[2] = "Bezhaberie";

	// субекти, щом се съдържа в контейнера, онзачава - да, демек става да е субект
	unsigned int numberOfOwners = 5;
	char** owner = new char*[numberOfOwners];
		owner[0] = "Babka";
		owner[1] = "Kmet";
		owner[2] = "Folk diva";
		owner[3] = "Traktor";
		owner[4] = "Kruchma";

	// действия
	unsigned int numberOfActions = 5;
	char** action = new char*[numberOfActions];
		action[0] = "sgazi";
		action[1] = "vdiga shum v";
		action[2] = "precakva";
		action[3] = "mirishe na";
		action[4] = "duvche";

	// обекти, щом се съдържа в контейнера, означава - да, демек става да е обект
	unsigned int numberOfObjects = 4;
	char** object = new char*[numberOfObjects];
		object[0] = "babka";
		object[1] = "kmet";
		object[2] = "folk diva";
		object[3] = "traktor";

	// изнесено вън от loop-а, защотот иначе сийда е еднакъв за loop-а и дава едни и същи рандом парчета, т.е loop е много бърз и сийда е едно и също време винаги
	srand(time(NULL));

	while(numberOfHeadings)
	{
		// взимам си рандом думички за съответните категории в стрингове
		char* expressFeeling = getRandomWord(expressions, numberOfExpressions);		//възклицание
		char* boostFeeling = getEmotional();										//удивителни
		char* ownerOfAction = getRandomWord(owner, numberOfOwners);					//субект
		char* actionOfOwner = getRandomWord(action, numberOfActions);				//действие
		char* objectOfAction = getRandomWord(object, numberOfObjects);				//обект

		int spacesBetweenCategories = 5 - 2;			// 5 - броя на категориите; 2 - първата дума + удивителни = една дума + последната дума = 2
		// сборът на дължините на отделните думи
		int wordsLength = strlen(expressFeeling) + strlen(boostFeeling) + strlen(ownerOfAction) + strlen(actionOfOwner) + strlen(objectOfAction);
		wordsLength += spacesBetweenCategories + 1;		// заради '\0'

		// динамично заделен масив със горния размер
		char * finalHeading = new char[wordsLength];
		finalHeading[0] = '\0';		// за да не дава фира конкатенацията и да си знае правилно къде е края на стринга

		strcat(finalHeading, expressFeeling);	//лепим възклицание
		strcat(finalHeading, boostFeeling);		//лепим удивителни
		strcat(finalHeading, " \0");			//лепим интервал
		strcat(finalHeading, ownerOfAction);	//лепим субект
		strcat(finalHeading, " \0");			//лепим интервал
		strcat(finalHeading, actionOfOwner);	//лепим действие
		strcat(finalHeading, " \0");			//лепим интервал
		strcat(finalHeading, objectOfAction);	//лепим обект
		
		std::cout << finalHeading << "\n";		// принтим сензацията/новината
		delete[] finalHeading;
		
		numberOfHeadings--;						// намалям итератора
	}

	delete[] expressions;
	delete[] owner;
	delete[] action;
	delete[] object;

	return 0;
}