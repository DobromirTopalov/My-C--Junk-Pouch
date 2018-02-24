#include <iostream>

int visibleIndians(int arr[],int size)
{
	int counter=1;
	bool isVisible = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				isVisible = true;
			}
			else
			{
				isVisible = false;
				break;
			}
		}
		if (isVisible)
		{
			counter++;
		}
		else
		{
			continue;
		}
	}
	return counter;
}

int main() 
{
	int arr[] = { 150,163,158,180,173 };
	int size = 5;

	std::cout << visibleIndians(arr, size)<<"\n";

	return 0;
}