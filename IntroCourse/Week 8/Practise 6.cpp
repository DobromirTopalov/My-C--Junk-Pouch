/*���.6
�������� ��� ���� ����� a � b � �������� ���� ���� �������� �� ��������, ����� �� � ��������� [a, b].*/

#include <iostream>

void printarr(int arr[], int a, int b)
{
	for (int i = a; i <= b; i++)
	{
		std::cout << arr[i] << " ";
	}
}


int main()
{
	int arr[] = { 2,7,5,4,6,9 };
	int a, b;
	std::cin >> a >> b;

	printarr(arr,a,b);
	std::cout << "\n";

	return 0;
}