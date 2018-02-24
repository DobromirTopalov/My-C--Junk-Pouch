#include <iostream>

bool isBalanced(unsigned int arr[], int size)
{
	int mid = 0 + (size - 0) / 2;
	int firstSum = 0;
	int secondSum = 0;

	for (int i = 0; i < mid; i++)
	{
		firstSum += arr[i];
	}
	for (int j = mid+1; j < size; j++)
	{
		secondSum += arr[j];
	}

	if (firstSum == secondSum)
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
	unsigned int listOne[] = { 5,10,4,1,7,3,9 };
	unsigned int listTwo[] = { 5,10,4,1,7,6,9 };
	int size = 7;

	std::cout << isBalanced(listOne, size) << "\n";
	std::cout << isBalanced(listTwo, size) << "\n";

	return 0;
}