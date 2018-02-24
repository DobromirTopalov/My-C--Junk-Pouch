/*Зад.5
Намерете най-малкото и най-голямото число в редицата.*/

#include <iostream>

void minmax(int arr[])
{
	int min = arr[0];
	int max = arr[0];
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		else if (arr[i] <= min)
		{
			min = arr[i];
		}
	}
	std::cout << "min= " << min << " and " << "max= " << max << "\n";
}


int main()
{
	int arr[] = { 2,7,5,4,6,9 };
	minmax(arr);

	return 0;
}