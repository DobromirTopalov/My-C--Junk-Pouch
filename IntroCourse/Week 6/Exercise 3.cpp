/*Зад.3
Да се напише функция, която приема естествено число като параметър и връща числото на фибоначи с пореден номер това число.*/

#include <iostream>

int fibonum(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
		return fibonum(num-2) + fibonum(num - 1);
}

int main()
{
	int num;
	std::cin >> num;
	
	std::cout << fibonum(num)<<"\n";

	return 0;
}