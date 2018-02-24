/*Зад.0 Да се състави програма на C++, чрез която по въведен низ съдържащ букви, цифри, знак минус '-' се извежда сборът на въведените
числа като се отчита знакът '-' пред съответното число.*/

#include <iostream>

int sum(char* text)
{
	bool sign = false;
	bool numeric = false;
	int sum = 0;
	int number=0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if ((text[i] == '-') && (text[i + 1] >= '0') && (text[i + 1] <= '9'))
		{
			sign = true;
		}
		if ((text[i] >= '0') && (text[i] <= '9'))
		{
			numeric = true;
			number += text[i] - '0';
			if ((text[i + 1] >= '0') && (text[i + 1] <= '9'))
			{
				number *= 10;
				continue;
			}
		}
		if (sign)
		{
			number *= (-1);
		}
		if (numeric)
		{
			sum += number;
			number = 0;
			sign = false;
			numeric = false;
		}

	}
	return sum;
}

int main()
{
	char* text = new char[10000];
	std::cin.getline(text, 10000);
	std::cout<<sum(text)<<"\n";


	return 0;
}