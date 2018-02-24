/*���.8
�� �� ������� �������� (C++), ���� ����� �� ������� ���������� ����� N �� ��������� [5..25]. �� �� ������� N ���� ���������� ����������
�����. ���������� �� �������� ���� ���� ����� � �� ��������� ��������� �� ��������� �� ������� ��� ������ � �����.*/


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

void deletearr(float arr[], int n,int index)
{
	for (int i = index; i < n-1; i++)
	{
		arr[i] = arr[i + 1];
	}
}

int main()
{
	float arrone[1000];
	
	int number;
	std::cin >> number;

	if (number >= 5 && number <= 25)
	{
		fillarr(arrone, number);
		printarr(arrone, number);
		deletearr(arrone, number, 2);
		printarr(arrone, number-1);
	}

	return 0;
}