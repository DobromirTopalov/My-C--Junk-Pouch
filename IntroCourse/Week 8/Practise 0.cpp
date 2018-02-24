/*Зад.0
Намерете сумата и средното аритметично на числата. Нека числата са от тип double.*/

#include <iostream>

double sum(double arr[])
{
	double result = 0;
	for (int i = 0; i < 5; i++)
	{
		result += arr[i];
	}
	return result;
}

double average(double arr[])
{
	double result = 0;
	for (int i = 0; i < 5; i++)
	{
		result += arr[i];
	}
	return result/5;
}
int main()
{
	double arr[] = {2.0,8.7,4.2,1.4,3.36};
	std::cout << sum(arr) << " and " << average(arr) << "\n";


	return 0;
}