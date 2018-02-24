#include <iostream>

bool biColor(int arr[], int size)
{
	int sum1=0, sum2=0;
	for (int i = 0; i < size; i += 2)
	{
		if ((arr[i] % 10==0))
		{
			while (arr[i] % 10)
			{
				arr[i] /= 10;
			}
		}
		while (arr[i] % 10)
		{
			sum1 += arr[i] % 10;
			arr[i] /= 10;
		}
	}

	for (int i = 1; i < size; i += 2)
	{
		if ((arr[i] % 10)==0)
		{
			while (arr[i] % 10)
			{
				arr[i] /= 10;
			}
		}
		while (arr[i] % 10)
		{
			sum2 += arr[i] % 10;
			arr[i] /= 10;
		}
	}

	if (sum1 == sum2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int arr[] = { 121,845,76,24,42 };
	int arr2[] = { 121,84,76,24,42 };
	int size = 5;

	std::cout << std::boolalpha << biColor(arr, size) << "\n";
	std::cout << std::boolalpha << biColor(arr2, size) << "\n";

	return 0;
}