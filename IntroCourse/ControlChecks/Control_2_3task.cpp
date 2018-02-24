#include <iostream>

int minOccurs(char arr[])
{
	bool isLetter = false;
	int min = 100000;
	int temp = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (((arr[i] > 'A') && (arr[i] < 'Z')) || ((arr[i] > 'a') && (arr[i] < 'z')))
		{
			isLetter = true;
			for (int j = 0; arr[j] != '\0'; j++)
			{
				if (arr[i] == arr[j])
				{
					temp++;
				}
				else if (arr[i] == (arr[j] - 32))
				{
					temp++;
				}
				else if (arr[i] == (arr[j] + 32))
				{
					temp++;
				}
			}
			if (min >= temp)
			{
				min = temp;
				temp = 0;
			}
			else
			{
				temp = 0;
				continue;
			}
		}
	}
	if (!(isLetter))
	{
		return 0;
	}
	return min;
}

int main()
{
	char arrOne[] = "Mama & papa";
	char arrTwo[] = "DobroOomir";
	char arrThree[] = "Dobri";
	std::cout << minOccurs(arrOne) << "\n";
	std::cout << minOccurs(arrTwo) << "\n";
	std::cout << minOccurs(arrThree) << "\n";

	return 0;
}