#include <iostream>

int maxOccurs(char arr[])
{
	bool isDigit = false;
	int max = 0;;
	int temp = 0;

	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (((arr[i] >= '0') && (arr[i] <= '9')))
		{
			isDigit = true;
			for (int j = 0; arr[j] != '\0'; j++)
			{
				if (arr[i] == arr[j])
				{
					temp++;
				}
			}
			if (max <= temp)
			{
				max = temp;
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
	return max;
}

int main()
{
	char arrOne[] = "(8+(2*3)-(4*8))";
	char arrTwo[] = "DobroOomir";
	char arrThree[] = "Dobri";
	std::cout << maxOccurs(arrOne) << "\n";
	std::cout << maxOccurs(arrTwo) << "\n";
	std::cout << maxOccurs(arrThree) << "\n";

	return 0;
}