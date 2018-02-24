/*«ад.4
Ќамерете сумата само на елементите на четни позиции в редицата. Ќамерете сумата само на елементите на нечетни позиции в редицата.*/


#include <iostream>

int evenSum(int arr[])
{
	int sum = 0;
	for (int i = 0; i < 6; i+=2)
	{
		sum+=arr[i];
	}
	return sum;
}

int oddSum(int arr[])
{
	int sum = 0;
	for (int i = 1; i < 6; i += 2)
	{
		sum += arr[i];
	}
	return sum;
}

int main()
{
	int arr[] = { 2,7,5,4,6,9 };
	std::cout << evenSum(arr)<<" and "<<oddSum(arr) << "\n";

	return 0;
}