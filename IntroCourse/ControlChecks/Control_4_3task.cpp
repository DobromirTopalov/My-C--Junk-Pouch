#include <iostream>

int minOccurs(char arr[])
{
	bool isDigit = false;
	int min = 100000;
	int temp = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if ((arr[i] >= '0') && (arr[i] <= '9'))
		{
			isDigit = true;
			for (int j = 0; arr[j] != '\0'; j++)
			{
				if (arr[i] == arr[j])
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
	if (!(isDigit))
	{
		return 0;
	}
	return min;
}

int main()
{
	char arrOne[] = "1337 15 57331";
	char arrTwo[] = "DobroOomir";
	char arrThree[] = "Dobri";
	std::cout << minOccurs(arrOne) << "\n";
	std::cout << minOccurs(arrTwo) << "\n";
	std::cout << minOccurs(arrThree) << "\n";

	return 0;
}