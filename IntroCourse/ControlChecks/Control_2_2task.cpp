#include <iostream>

int sumofelements(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if (!(arr[i] % 10))
		{
			while ((!(arr[i] % 10)))
			{
				arr[i] /= 10;
			}
		}
		while (arr[i] % 10)
		{
			sum += arr[i] % 10;
			arr[i] /= 10;
		}
	}
	return sum;
}

int compareArrays(int arr1[], int arr2[],int size1, int size2)
{
	int firstarr = sumofelements(arr1, size1);
	int secondarr = sumofelements(arr2, size2);

	if (firstarr == secondarr)
	{
		return 0;
	}
	else if (firstarr > secondarr)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int arr1[] = { 5,124,77,10 };
	int size1 = 4;
	int arr2[] = { 42981,1000,32,225, };
	int size2 = 4;
	
	std::cout << compareArrays(arr1,arr2, size1,size2) << "\n";

	return 0;
}