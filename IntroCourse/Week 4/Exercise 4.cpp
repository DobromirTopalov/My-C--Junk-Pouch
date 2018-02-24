/*Зад.4
Напишете програма, която приема цяло число n и намира (2n)!!*/


#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	int multi = 2 * number;			
	int result = 1;

	int i = 0;
	while(multi>2)					
	{
		multi = (2 * number)-i;
		result *= (multi);			
		i += 2;
	}

	std::cout << result << "\n";

	return 0;
}