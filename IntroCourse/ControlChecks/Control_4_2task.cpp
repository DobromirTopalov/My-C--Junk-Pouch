#include <iostream>

int longestSimilar(int arr1[], int arr2[], int size)
{
	int sum1 = 0;
	int sum2 = 0;
	int counter = 0;

	for (int i = 0; i < size; i++)
	{
		if (!(arr1[i] % 10))
		{
			while ((!(arr1[i] % 10)))
			{
				arr1[i] /= 10;
			}
		}
		while (arr1[i] % 10)
		{
			sum1 += arr1[i] % 10;
			arr1[i] /= 10;
		}

		if (!(arr2[i] % 10))
		{
			while ((!(arr2[i] % 10)))
			{
				arr2[i] /= 10;
			}
		}
		while (arr2[i] % 10)
		{
			sum2 += arr2[i] % 10;
			arr2[i] /= 10;
		}

		if (sum1 == sum2)
		{
			counter++;
		}
		else
		{
			break;
		}
	}
	return counter;
}

int main()
{
	int arr1[] = { 12,35,54,72,999 };
	int arr2[] = { 21,80,117,51,91 };
	int size = 5;

	std::cout << longestSimilar(arr1, arr2, size) << "\n";

	return 0;
}