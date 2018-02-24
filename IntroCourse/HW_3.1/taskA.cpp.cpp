/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 3А
* @compiler VC
*
*/

#include <iostream>
#include <cstring>

// правя началния стринг удобен за ползване
void getRidOfSpaces(char** string) {
	int size = strlen(*string);

	// за да намеря размера на новия стринг
	int countLegitSymbols = 0;
	for (int i = 0; i < size; i++) {
		if ((*string)[i] != ' ')
		{
			countLegitSymbols++;
		}
	}

	// създаване на нов стринг с правилна дължина
	char* newString = new char[countLegitSymbols + 1];

	// пълнене на новия стринг
	for (int k = 0, i = 0; k < countLegitSymbols; i++) {
		if ((*string)[i] != ' ')
		{
			newString[k] = (*string)[i];
			k++;
		}
	}
	newString[countLegitSymbols] = '\0';
	
	//насочвам стария(т.е външния хваща хийп меморито)
	*string = newString;
	newString = nullptr;
}

// търся индекси
int findIndex(char* string, int start)
{
	// търся възможно най-вътрешните скоби/изрази
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
		// връщам индекса на скобата,която затваря израза
		if (startCount == 0 && isOkay) {
			return i;
		}
	}
	// няма скоби
	return -1;
}

// повтарям стринг, брой пъти
void repeat(char** string, int times) {
	int size = strlen(*string);

	// създаване на нов стринг с правилна дължина
	char* newString = new char[size * times + 1];

	// пълнене на новия стринг
	for (int k = 0, i = 0; k < size * times; i++,k++) {
		if (i == size) {
			i = 0;
		}
		newString[k] = (*string)[i];
	}
	newString[size*times] = '\0';

	//насочвам стария(т.е външния хваща хийп меморито)
	delete[](*string);
	*string = newString;
	newString = nullptr;
}

// заменям част от даден стринг с друг
void replace(char** string, int from, int to, char* additionalString) {
	int size = strlen(*string) - (to - from + 1) + strlen(additionalString);

	// създаване на нов стринг с правилна дължина
	char* newString = new char[size + 1];

	// пълнене на новия стринг
	// копиране на данни от 0 до from на главния стринг
	for (int i = 0; i < from; i++)
	{
		newString[i] = (*string)[i];
	}

	//	копиране на данни от from до край на стринга за копиране
	for (int i = from, k=0; k < strlen(additionalString); i++,k++)
	{
		newString[i] = (additionalString)[k];
	}

	// копиране на остатъка от главния стринг
	for (int i = from + (to-from+1), k = strlen(additionalString) + from; i < strlen(*string); i++,k++)
	{
		newString[k] = (*string)[i];
	}
	newString[size] = '\0';

	//насочвам стария(т.е външния хваща хийп меморито)
	delete[] (*string);
	*string = newString;
	newString = nullptr;
}

// използвам стековата рамка на рекурсията
char* rec(char** string)
{
	int repeated = 0;
	int startIndex = 0;
	int endIndex = strlen(*string);

	int subStartIndex = 0;
	int subEndIndex = 0;

	char* newString;

	// обхождам стринга
	for (int charAt = 0; charAt < strlen(*string); charAt++) {
		//намирам отваряща скоба - режа стринга от нея до края
		if ((*string)[charAt] == '(') {
			startIndex = charAt + 1;
			newString = new char[endIndex - startIndex + 1];

			strncpy(newString, (*string) + startIndex, endIndex - startIndex);
			newString[endIndex - startIndex] = '\0';
			
			//викам рекурсивно с новия отрязан стринг
			char* tempString = rec(&newString);
			delete[] newString;

			repeat(&tempString, repeated);		// готово парче текст - плаче за употреба по-късно

			//ако все още има скобка - намирам я къде е индекса, за да риплейсна с tempString(плачещото парче)
			if (strstr(*string,")") != nullptr) {
				//намирам индекса
				subEndIndex = findIndex(*string, 0);
				//риплейс директно върху стринга (референцията)
				replace(&*string, subStartIndex, subEndIndex, tempString);
				
				//занулявам стойностите, заради фор-цикъла - трябва да обхождам наново все едно съм си извикал пак функцията със вече по-оформен низ
				repeated = 0;
				startIndex = 0;
				endIndex = strlen(*string);
				subStartIndex = 0;
				subEndIndex = 0;
				delete[] tempString;
				charAt = 0;
			}
		}													// при този тип скоба - намираме частта между ( и ) и я връщаме - дъното
		else if ((*string)[charAt] == ')') {
			endIndex = charAt;
			char* slicedString = new char[endIndex - startIndex + 1];

			strncpy(slicedString, (*string) + startIndex, endIndex - startIndex);
			slicedString[endIndex - startIndex] = '\0';
			
			return (slicedString); // tempString прихваща меморито
		}	//режа си числото пред скобите и го пазя
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
	

	// за различните инпути, ползваме съответния инпут (при тестване)
	getRidOfSpaces(&input3);
	char* result = rec(&input3);

	std::cout << result << "\n";



	// result реферира към съответния инпут, който използваме - като трием result трием и input-a
	delete[] result;
	return 0;
}