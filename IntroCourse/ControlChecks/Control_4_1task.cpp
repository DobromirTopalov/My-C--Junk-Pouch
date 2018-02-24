#include <iostream>

int visibleIndians(unsigned int arr[], int size)
{
	bool isVisible = true;
	int counter = 0;
	for (int i = 0; i <size; i++)
	{
		for (int j = i + 1; j < size; j++)
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
		if (!(isVisible))
		{
			counter++;
		}
	}
	return counter;
}

int main()
{
	unsigned int indians[] = { 173,180,158,163,150 };
	int size = 5;
	std::cout << visibleIndians(indians, size) << "\n";

	return 0;
}