/*���.4
��������, �� ������ 4-������� ����� � ��������, ��� ������ �� 2 ����� �������� � ������� �� 2 �����. 
�� �� ������� ��������, ����� ������� ���� ������������ ���������� ����� �� ��������� [1000 .. 9999] 
�� ��������� �� �������� �����. ����������� ����� while.*/

#include <iostream>

int main()
{
	
	bool isOkay = true;
	int number;

	while (isOkay)
	{
		std::cin >> number;
		if (number / 100 == number % 100)
		{
			isOkay = false;
			break;
		}
		
	}

	std::cout << "\n";


	return 0;
}