/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3�
* @compiler VC
*
*/

#include <iostream>
#include <cstring>

// ����� �������� ������ ������ �� ��������
void getRidOfSpaces(char** string) {
	int size = strlen(*string);

	// �� �� ������ ������� �� ����� ������
	int countLegitSymbols = 0;
	for (int i = 0; i < size; i++) {
		if ((*string)[i] != ' ')
		{
			countLegitSymbols++;
		}
	}

	// ��������� �� ��� ������ � �������� �������
	char* newString = new char[countLegitSymbols + 1];

	// ������� �� ����� ������
	for (int k = 0, i = 0; k < countLegitSymbols; i++) {
		if ((*string)[i] != ' ')
		{
			newString[k] = (*string)[i];
			k++;
		}
	}
	newString[countLegitSymbols] = '\0';
	
	//�������� ������(�.� ������� ����� ���� ��������)
	*string = newString;
	newString = nullptr;
}

// ����� �������
int findIndex(char* string, int start)
{
	// ����� �������� ���-���������� �����/������
	const int size = strlen(string);
	int startCount = start;
	bool isOkay = start;
	for (int i = 0; i < size; i++) {
		if (string[i] == '(') {
			startCount++;
			isOkay = true;
			continue;
		}
		else if (string[i] == ')') {
			startCount--;
		}
		// ������ ������� �� �������,����� ������� ������
		if (startCount == 0 && isOkay) {
			return i;
		}
	}
	// ���� �����
	return -1;
}

// �������� ������, ���� ����
void repeat(char** string, int times) {
	int size = strlen(*string);

	// ��������� �� ��� ������ � �������� �������
	char* newString = new char[size * times + 1];

	// ������� �� ����� ������
	for (int k = 0, i = 0; k < size * times; i++,k++) {
		if (i == size) {
			i = 0;
		}
		newString[k] = (*string)[i];
	}
	newString[size*times] = '\0';

	//�������� ������(�.� ������� ����� ���� ��������)
	delete[](*string);
	*string = newString;
	newString = nullptr;
}

// ������� ���� �� ����� ������ � ����
void replace(char** string, int from, int to, char* additionalString) {
	int size = strlen(*string) - (to - from + 1) + strlen(additionalString);

	// ��������� �� ��� ������ � �������� �������
	char* newString = new char[size + 1];

	// ������� �� ����� ������
	// �������� �� ����� �� 0 �� from �� ������� ������
	for (int i = 0; i < from; i++)
	{
		newString[i] = (*string)[i];
	}

	//	�������� �� ����� �� from �� ���� �� ������� �� ��������
	for (int i = from, k=0; k < strlen(additionalString); i++,k++)
	{
		newString[i] = (additionalString)[k];
	}

	// �������� �� �������� �� ������� ������
	for (int i = from + (to-from+1), k = strlen(additionalString) + from; i < strlen(*string); i++,k++)
	{
		newString[k] = (*string)[i];
	}
	newString[size] = '\0';

	//�������� ������(�.� ������� ����� ���� ��������)
	delete[] (*string);
	*string = newString;
	newString = nullptr;
}

// ��������� ��������� ����� �� ����������
char* rec(char** string)
{
	int repeated = 0;
	int startIndex = 0;
	int endIndex = strlen(*string);

	int subStartIndex = 0;
	int subEndIndex = 0;

	char* newString;

	// �������� �������
	for (int charAt = 0; charAt < strlen(*string); charAt++) {
		//������� �������� ����� - ���� ������� �� ��� �� ����
		if ((*string)[charAt] == '(') {
			startIndex = charAt + 1;
			newString = new char[endIndex - startIndex + 1];

			strncpy(newString, (*string) + startIndex, endIndex - startIndex);
			newString[endIndex - startIndex] = '\0';
			
			//����� ���������� � ����� ������� ������
			char* tempString = rec(&newString);
			delete[] newString;

			repeat(&tempString, repeated);		// ������ ����� ����� - ����� �� �������� ��-�����

			//��� ��� ��� ��� ������ - ������� � ���� � �������, �� �� ��������� � tempString(��������� �����)
			if (strstr(*string,")") != nullptr) {
				//������� �������
				subEndIndex = findIndex(*string, 0);
				//������� �������� ����� ������� (������������)
				replace(&*string, subStartIndex, subEndIndex, tempString);
				
				//��������� �����������, ������ ���-������ - ������ �� �������� ������ ��� ���� ��� �� ������� ��� ��������� ��� ���� ��-������� ���
				repeated = 0;
				startIndex = 0;
				endIndex = strlen(*string);
				subStartIndex = 0;
				subEndIndex = 0;
				delete[] tempString;
				charAt = 0;
			}
		}													// ��� ���� ��� ����� - �������� ������ ����� ( � ) � � ������� - ������
		else if ((*string)[charAt] == ')') {
			endIndex = charAt;
			char* slicedString = new char[endIndex - startIndex + 1];

			strncpy(slicedString, (*string) + startIndex, endIndex - startIndex);
			slicedString[endIndex - startIndex] = '\0';
			
			return (slicedString); // tempString �������� ��������
		}	//���� �� ������� ���� ������� � �� ����
		else if ((*string)[charAt] >= '0' && (*string)[charAt] <= '9') {
			if (subStartIndex == 0) {
				subStartIndex = charAt;
			}
			repeated = repeated * 10 + ((*string)[charAt] - '0');
		}
	}
	return *string;
}


int main()
{
	
	//char* input = "AABC";
	//char* input2 = "R2 (AB) 3 (Z)";
	char* input3 = "AB12 (X) 2 (B3 (A) )";
	

	// �� ���������� ������, �������� ���������� ����� (��� ��������)
	getRidOfSpaces(&input3);
	char* result = rec(&input3);

	std::cout << result << "\n";



	// result �������� ��� ���������� �����, ����� ���������� - ���� ����� result ����� � input-a
	delete[] result;
	return 0;
}