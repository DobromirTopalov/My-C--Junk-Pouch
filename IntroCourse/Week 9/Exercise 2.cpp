/*���.2 Speak the digits
�������� �������, ����� ��������� �������� ���, ���� ������ ������� �� ���� - ��������� ����.*/


#include <iostream>

void inverse(char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		switch (arr[i])
		{
		case '0': std::cout << "zero"; break;
		case '1': std::cout << "one"; break;
		case '2': std::cout << "two"; break;
		case '3': std::cout << "three"; break;
		case '4': std::cout << "four"; break;
		case '5': std::cout << "five"; break;
		case '6': std::cout << "six"; break;
		case '7': std::cout << "seven"; break;
		case '8': std::cout << "eight"; break;
		case '9': std::cout << "nine"; break;
		default: std::cout << arr[i];
			break;
		}

	}

}

int main()
{
	char string[] = "� ���� 0 ����������, 7 �������� � 3 ����� � �����!�����������!";
	inverse(string);
	std::cout << "\n";


	return 0;
}