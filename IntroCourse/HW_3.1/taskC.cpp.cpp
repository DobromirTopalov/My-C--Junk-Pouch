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
	
	// �����������
	unsigned int numberOfExpressions = 3;
	char** expressions = new char*[numberOfExpressions];
		expressions[0] = "Shok";
		expressions[1] = "Skandal";
		expressions[2] = "Bezhaberie";

	// �������, ��� �� ������� � ����������, �������� - ��, ����� ����� �� � ������
	unsigned int numberOfOwners = 5;
	char** owner = new char*[numberOfOwners];
		owner[0] = "Babka";
		owner[1] = "Kmet";
		owner[2] = "Folk diva";
		owner[3] = "Traktor";
		owner[4] = "Kruchma";

	// ��������
	unsigned int numberOfActions = 5;
	char** action = new char*[numberOfActions];
		action[0] = "sgazi";
		action[1] = "vdiga shum v";
		action[2] = "precakva";
		action[3] = "mirishe na";
		action[4] = "duvche";

	// ������, ��� �� ������� � ����������, �������� - ��, ����� ����� �� � �����
	unsigned int numberOfObjects = 4;
	char** object = new char*[numberOfObjects];
		object[0] = "babka";
		object[1] = "kmet";
		object[2] = "folk diva";
		object[3] = "traktor";

	// �������� ��� �� loop-�, ������� ����� ����� � ������� �� loop-� � ���� ���� � ���� ������ �������, �.� loop � ����� ���� � ����� � ���� � ���� ����� ������
	srand(time(NULL));

	while(numberOfHeadings)
	{
		// ������ �� ������ ������� �� ����������� ��������� � ���������
		char* expressFeeling = getRandomWord(expressions, numberOfExpressions);		//�����������
		char* boostFeeling = getEmotional();										//����������
		char* ownerOfAction = getRandomWord(owner, numberOfOwners);					//������
		char* actionOfOwner = getRandomWord(action, numberOfActions);				//��������
		char* objectOfAction = getRandomWord(object, numberOfObjects);				//�����

		int spacesBetweenCategories = 5 - 2;			// 5 - ���� �� �����������; 2 - ������� ���� + ���������� = ���� ���� + ���������� ���� = 2
		// ������ �� ��������� �� ��������� ����
		int wordsLength = strlen(expressFeeling) + strlen(boostFeeling) + strlen(ownerOfAction) + strlen(actionOfOwner) + strlen(objectOfAction);
		wordsLength += spacesBetweenCategories + 1;		// ������ '\0'

		// ��������� ������� ����� ��� ������ ������
		char * finalHeading = new char[wordsLength];
		finalHeading[0] = '\0';		// �� �� �� ���� ���� �������������� � �� �� ���� �������� ���� � ���� �� �������

		strcat(finalHeading, expressFeeling);	//����� �����������
		strcat(finalHeading, boostFeeling);		//����� ����������
		strcat(finalHeading, " \0");			//����� ��������
		strcat(finalHeading, ownerOfAction);	//����� ������
		strcat(finalHeading, " \0");			//����� ��������
		strcat(finalHeading, actionOfOwner);	//����� ��������
		strcat(finalHeading, " \0");			//����� ��������
		strcat(finalHeading, objectOfAction);	//����� �����
		
		std::cout << finalHeading << "\n";		// ������� ����������/��������
		delete[] finalHeading;
		
		numberOfHeadings--;						// ������� ���������
	}

	delete[] expressions;
	delete[] owner;
	delete[] action;
	delete[] object;

	return 0;
}