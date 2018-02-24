/*Зад.4
Приемаме, че дадено 4-цифрено число е щастливо, ако левите му 2 цифри съвпадат с десните му 2 цифри. 
Да се състави програма, която въвежда чрез клавиатурата естествени числа от интервала [1000 .. 9999] 
до въвеждане на щастливо число. Използвайте цикъл while.*/

#include <iostream>

int main()
{
	
	bool isOkay = true;
	int number;

	while (isOkay)
	{
		std::cin >> number;
		if (number / 100 == number % 100)
		{
			isOkay = false;
			break;
		}
		
	}

	std::cout << "\n";


	return 0;
}