#include <iostream>
#include <cstring>

void concat(char* buffer, char temp)
{
	int size = strlen(buffer);
	buffer[size] = temp;
	buffer[size + 1] = '\0';
}

void strGet(char* buffer)
{
	char temp;
	int i = 0;
	
	do 
	{
		std::cin >> temp;
		if (temp == '\n')
		{
			temp = '\0';
		}
		else
		{
			concat(buffer, temp);
		}

	} while (temp != '\0');

}

int main()
{
	char* buffer="";
	strGet(buffer);
	//std::cout << buffer;
	


	return 0;
}