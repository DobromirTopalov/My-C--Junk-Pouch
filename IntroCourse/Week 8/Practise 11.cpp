/*���.11
����� ��� ������ ��������� ���������� �����. ����������� �� 1-���� ������ �� �������� �������������, � ��� ������� �� �������� �� 
������������. �� �� ������� �������� (C++), ���� ����� �� ��������� ���� ������ ����� �� ������� ������ �� ����� � �� ������� ������,
�.�. ���� ������� ������ � ������������ �� ������ ������.*/

#include <iostream>

void fillarr(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void printarr(float arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

bool scalararr(float arr[], float arr2[],int n)
{
	bool isInTwo = false;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < n; j++)
		{
			isInTwo = false;
			if (arr[i] == arr2[j])
			{
				isInTwo = true;
				break;
			}
		}

		if (!isInTwo)
		{
			isInTwo = false;
			return false;
		}

	}
	return isInTwo;
}

int main()
{
	float arrone[] = {3,2,7,9,5,4,12,-7,0};
	float arrtwo[1000];

	int number;
	std::cin >> number;

	if (number >= 1 && number <= 1000)
	{
		fillarr(arrtwo, number);
		std::cout<<std::boolalpha<<scalararr(arrone, arrtwo,number)<<"\n";
	}

	return 0;
}