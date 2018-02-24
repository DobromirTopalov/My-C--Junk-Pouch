#include <iostream>

int Fibo(int number)
{
	if (number <= 0)
	{
		return 0;
	}
	else if (number == 1)
	{
		return 1;
	}
	else
	{
		return Fibo(number - 1) + Fibo(number - 2);
	}
	
}

int main()
{
	int number;
	std::cin >> number;
	for(int i=0;i<number;i++)
	std::cout<<Fibo(i)<<" ";

	std::cout << "\n";
	return 0;
}