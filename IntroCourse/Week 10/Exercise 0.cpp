/*Зад.0 Length?
Напишете функция, която намира дължината на символен низ.*/

#include <iostream>

int length(char* arr)
{
	int length = 0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		length++;
	}
	return length;
}

int main()
{
	char* string = "ASdqwdes!";
	std::cout << length(string) << "\n";


	return 0;
}