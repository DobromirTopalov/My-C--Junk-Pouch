/*���.1 Inverse letters
�������� �������, ����� ��������� �������� ���, ���� ������ ������ ������ ����� � ����� � ������ ����� ����� - � ������.*/

#include <iostream>

void inverse(char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if ((arr[i] >= 'a') && (arr[i] <= 'z'))
		{
			arr[i] -= ('a' - 'A');
		}
		else if ((arr[i] >= 'A') && (arr[i] <= 'Z'))
		{
			arr[i] += ('a' - 'A');
		}
		std::cout << arr[i];
	}

}

int main()
{
	char string[] = "aSdqwASDdes";
	inverse(string);
	std::cout<< "\n";


	return 0;
}