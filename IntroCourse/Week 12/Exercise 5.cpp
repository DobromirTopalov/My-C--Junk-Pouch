/*���.5
�� �� ������ �������, ����� ������ ����� � ��� ������ � ������� ��� ����� � ����. ���������� ���� �������� �� ������� ����� ������ 
�� ����� �������� � �����. ��� ������ ������ � ��-�����, �� �� ������� "��������" ����� � ����. ��� � ��-����� - �� �������
���������� �� ����. �� �� ����� �������� ��� ����� �����.*/


#include <iostream>

void fillarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cin >> arr[i];
	}
}

void printarr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

int* newArr(int arr[], int size,int cursize)
{
	int* newarray = new int[size];
	if (cursize >= size)
	{
		for (int i = 0; i < size; i++)
		{
			newarray[i] = arr[i];
		}
	}
	else if (cursize < size)
	{
		for (int i = 0; i < cursize; i++)
		{
			newarray[i] = arr[i];
		}
		for (int i = cursize; i < size; i++)
		{
			newarray[i] = 0;
		}
	}

	return newarray;
}

int main()
{
	int const size = 7;
	int arr[size];
	int* arr2;
	
	fillarr(arr, size);
	printarr(arr, size);
	std::cout << "\n";
	arr2 = newArr(arr, 5, size);
	printarr(arr2, 5);

	std::cout << "\n";
	return 0;
}