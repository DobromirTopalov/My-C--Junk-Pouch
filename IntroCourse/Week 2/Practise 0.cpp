/*Зад.0
Да се напише програма, която проверява дали сумата от цифрите на дадено четирицифрено число е кратна на 3.*/

#include <iostream>

int main()
{
	int number, sum,digitone,digittwo,digitthree,digitfour;
	std::cin >> number;

	digitone = number / 1000;
	digittwo = (number / 100)%10;
	digitthree =(number / 10) % 10;
	digitfour = number % 10;
	sum = digitone + digittwo + digitthree + digitfour;
	
	if (sum % 3 == 0)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}


	return 0;
}