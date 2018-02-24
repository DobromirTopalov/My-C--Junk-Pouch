/*���.7
�������� ��������, ����� �������� �������� ��� n-����� �������. �� ����� ��������� n (1 <= n <= 100) � ��� ������ �� n ������ �����, 
����� �� ����������� ���������� �� ����� �������.*/

#include <iostream>

void fillarr(float arr[],int n)
{
	for (int i=0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

void printarr(float arr[], int n)
{
	for (int i=0; i < n; i++)
	{
		std::cout << arr[i]<<" ";
	}
	std::cout << "\n";
}

void scalararr(float arr[],float arr2[],int n)
{
	for (int i=0; i < n; i++)
	{
		arr[i]*=arr2[i];
	}
}

int main()
{
	float arrone[1000];
	float arrtwo[1000];

	int number;
	std::cin >> number;

	if (number >= 1 && number <= 100)
	{
		fillarr(arrone, number);
		fillarr(arrtwo, number);
		scalararr(arrone, arrtwo, number);
		printarr(arrone, number);
	}

	return 0;
}