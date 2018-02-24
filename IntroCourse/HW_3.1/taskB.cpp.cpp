/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3B
* @compiler VC
*
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iomanip>

void printDynamicWordCorrectly(char* word)
{
	int size = strlen(word);
	for (int i = 0; i < size; i++) {
		std::cout << word[i] << " ";
	}
}

int main()
{
	const char* words[] = { "apple", "orange", "month","vehicle" };
	const unsigned int MIN = 0;
	const unsigned int MAX = 4 - 1;

	// ������ ������ ������
		srand(time(NULL));
		int range = (MAX) - MIN + 1;
		int index = rand() % range + MIN;
	
	// ������ ������
		unsigned int wordSize = strlen(words[index]);
		char* wordToQuess = new char[wordSize + 1];
	
		strcpy(wordToQuess, words[index]);

	// ����� ������ ��-����� �� �������� � ��-������ ���
		for (int i = 0; wordToQuess[i] != '\0'; i++) {
			if (wordToQuess[i] >= 'A' && wordToQuess[i] <= 'Z') {
				wordToQuess[i] -= 'A' - 'a';
			}
		}

	// ������ �� ����������� - ����� �� ���������� ��������� ������
		unsigned int numberOfMistakes;
		std::cout << "Enter mistakes limit: ";
		std::cin >> numberOfMistakes;
		std::cout << "\n";
	
	// ��������� ����������� �� ����, ������� �� ������ ����������� �������
		char* dynamicWord = new char[wordSize + 1];
		for (int i = 0; i < wordSize; i++) {
			dynamicWord[i] = '_';
		}
		dynamicWord[wordSize] = '\0';

	// ������ �� ������ ���������� ���� - �������
		char* history = new char[wordSize + numberOfMistakes + 3];
		history[0] = '\0';
		
	// ������� ����������
	unsigned int countMistakes = 0;
	unsigned int totalMistakes = numberOfMistakes;

	
	// ����� �� ������, ������ ������
	std::cout << "Guess the word (max " << totalMistakes << " mistakes):\n\n";
	
	while (numberOfMistakes) {
		std::cout << "[" << countMistakes << "/" << totalMistakes << "] ";
		printDynamicWordCorrectly(dynamicWord);
		std::cout << "History: " << history << "\n";
		
		char userLetter = NULL;
		std::cout << "Choose a letter: ";
		std::cin >> userLetter;

		if ( (userLetter < 'a' || userLetter > 'z') || (userLetter >= 'A' && userLetter <= 'Z')) {
			std::cout << "Invalid Input\n";
			if (userLetter >= 'A' && userLetter <= 'Z') {
				std::cout << "Use only small letters!\n\n";
			}
			continue;
		}

		// ������ �� ���������, ����� �� � ����������, ����� �� ���� ���������� ������� ���� ������
			char temp[2];
			temp[0] = userLetter;
			temp[1] = '\0';

			// ���������� ������ ������������ �������
			char* tempHistory = new char[strlen(history) + 1];
			tempHistory[0] = '\0';
			strcpy(tempHistory, history);

			//���� ���������, �� ������ ������� �, ���� ���� �� ���������� � ������, �� �� ����� ���������
			int newSize = strlen(history) + 7;
			delete[] history;
			
			//������� ���� �����, ���� �� ������ ������ ��������� ������� �� ������� � ���� ������������ �������
			history = new char[newSize];
			history[0] = '\0';
			strcpy(history, tempHistory);
			delete[] tempHistory;

			//�������� �� ������ ����� � �������� ��� ������ ��������� �������
			strcat(history, " ");
			strcat(history, temp);
			
		// ������� � ������ �� �? ����� �� ��? - �� �� ������� �� ����� �������� ���������
		bool foundLetterInWord = false;
		for (int i = 0; i < wordSize; i++) {
			if (userLetter == wordToQuess[i]) {
				dynamicWord[i] = userLetter;
				foundLetterInWord = true;
			}
		}

		if (foundLetterInWord) {
			std::cout << "OK\n";
		}
		else {
			std::cout << "No such letter!\n";
			countMistakes++;
			numberOfMistakes--;
		}
		
		//��� �� ��� ��� ���������/��������� ����� � ������? - �� �� ������� ���� � ���� �� ������
		bool isOver = true;
		for (int i = 0; i < strlen(dynamicWord); i++) {
			if (dynamicWord[i] == '_') {
				isOver = false;
			}
		}

		if (isOver) {
			std::cout << "\n\n\nCongratulations! You've guessed right!\n";
			delete[] wordToQuess;
			delete[] dynamicWord;
			delete[] history;
			return 0;
		}

		std::cout << "\n";
	}
	
	std::cout << "\n\n\nYou've failed to guess the word!\n";
	

	delete[] wordToQuess;
	delete[] dynamicWord;
	delete[] history;
	return 0;
}