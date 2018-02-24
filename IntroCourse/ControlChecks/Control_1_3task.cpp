#include <iostream>

int maxOccurs(char arr[])
{
	bool isLetter = false;
	int letter = 0;;
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
			if (letter <= temp)
			{
				letter = temp;
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
	return letter;
}

int main()
{
	char arrOne[] = "OnomatOpoeia";
	char arrTwo[] = "DobroOomir";
	char arrThree[] = "Dobri";
	std::cout << maxOccurs(arrOne) << "\n";
	std::cout << maxOccurs(arrTwo) << "\n";
	std::cout << maxOccurs(arrThree) << "\n";

	return 0;
}