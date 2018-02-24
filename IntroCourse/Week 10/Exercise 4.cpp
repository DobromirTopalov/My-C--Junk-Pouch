/*Зад.4 Where is izdislav
Напишете булева функция, която приема символен низ и която връща true, ако низът завършва на izdislav и false в противен случай.*/

#include <iostream>
#include <cstring>

bool compare(char* arr1, char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);
	if (len2 > len1)
	{
		return false;
	}

	int start = len1 - len2 + 1;
	for (int i = start, p = 0; arr1[i] != '\0'; i++, p++)
	{
		if (arr1[i] == arr2[p])
		{
			continue;
		}
		else if (arr1[i] < arr2[p])
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	char string1[] = "Kurec and Putec izdislav";
	char string2[] = "izdislav";

	std::cout << std::boolalpha << compare(string1, string2);
	std::cout << "\n";


	return 0;
}