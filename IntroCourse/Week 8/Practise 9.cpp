/*���.9
�� �� ������� �������� (C++), ���� ����� � ��������� ����� ������������� �� �������� ������ ���������� ����� �� ��������� [0..5000].
���������� �� ������� ���� ���������� ��������, �.�. �� �� ��������� ������ �������� ��� �������� 0 � ���� ����������� ����
���������������� �� �� ���������� � ��� ������� �� ��������.*/

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
	for (int i = n-1; i >= 0; i--)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void deletearr(float arr[], int n, int index)
{
	for (int i = index; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
}

int rewritearr(float arr[], int number)
{
	int counter = 0;
	for (int i = 0; i < number; i++)
	{
		if (arr[i] == 0)
		{
			deletearr(arr, number, i);
			counter++;
		}
	}
	return counter;
}

int main()
{
	float arrone[1000];

	int number;
	std::cin >> number;

	if (number >= 1 && number <= 1000)
	{
		fillarr(arrone, number);
		//printarr(arrone, number);
		int newnumber = rewritearr(arrone, number);

		printarr(arrone, number - newnumber);
	}

	return 0;
}