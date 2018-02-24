/*Зад.5 Substring
Напишете функция, която приема два символни низа и проверява дали първия е подниз на втория.*/

#include <iostream>
#include <cstring>

bool substring(char* arr1, char* arr2, int index1, int index2)
{
	for (int i = index1, p = 0; i < index2; i++, p++)
	{
		if (arr1[i] == arr2[p])
		{
			continue;
		}
		else
		{
			return false;
		}
	}
	return true;
}

bool compare(char* arr1, char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	int end = 0;

	if (len2 > len1)
	{
		 end = len2;
	}
	else
	{
		end = len1;
	}

	bool isOk = false;
	for (int i = 0, p = 0; i < end; i++, p++)
	{
		isOk=substring(arr1, arr2, i, i + len2);
		if (isOk)
		{
			return true;
		}
	}
	return isOk;
}


int main()
{
	char string1[] = "Kurec, izdislav and Putec";
	char string2[] = "izdislav";

	std::cout << std::boolalpha << compare(string1, string2);
	std::cout << "\n";


	return 0;
}