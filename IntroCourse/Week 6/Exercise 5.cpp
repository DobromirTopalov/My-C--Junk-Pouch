/*Зад.5
Да се напише целочислена функция с параметри n и k, която намира цялото число, което се получава от положителното цяло число n като
се задраска k–тата му отдясно наляво цифра.
Например ако n е 31245 и k е 4, функцията трябва да намери числото 3245; ако k е 2, функцията трябва да намери числото 3125,
а ако n е 5 и k е 1, функцията трябва да намери числото 0.*/

#include <iostream>
#include <cmath>

int rewriteNum(int num, int n)
{
	int digits = (int)log10((double)abs(num) + 1);
	if (digits == 0 && n == 1)
	{
		return 0;
	}
	int cock = 1;
	int tail = 1;

	tail = num % (int)(pow(10, n - 1));
	cock = (num / (int)(pow(10, n)))*(pow(10,n-1));
	
	int newnum = cock+tail;

	return newnum;
}


int main()
{
	int n, k;
	std::cin >> n >> k;
	std::cout << rewriteNum(n, k) << "\n";

	return 0;
}