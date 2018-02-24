/*Зад.3 Лексикографска наредба
Напишете функция, която сравнява лексикографски два символни низа.*/

#include <iostream>
#include <cstring>

int compare(char* arr1,char* arr2)
{
	int len1 = strlen(arr1);
	int len2 = strlen(arr2);

	if (len1 < len2)
	{
		return -1;
	}
	else if (len1 > len2)
	{
		return 1;
	}
	else
	{
		for (int i = 0; arr1[i] != '\0'; i++)
		{
			if (arr1[i] == arr2[i])
			{
				continue;
			}
			else if (arr1[i] < arr2[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	char string1[] = "Kurec";
	char string2[] = "Putec";

	std::cout<<std::boolalpha<<compare(string1, string2);
	std::cout << "\n";


	return 0;
}