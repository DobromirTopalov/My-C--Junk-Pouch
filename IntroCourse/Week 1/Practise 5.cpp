/*���.5
�� �� �������� �� ������ 6-������� ����� ���� 3-��������� �����, 
���������� �� ������� 3 ����� �� ��������, � ��-����� �� ����, ���������� �� ������� 3.*/

#include <iostream>

int main()
{
	int number,fthree,sthree;
	std::cin >> number;
	
	fthree = number / 1000;
	sthree = number % 1000;

	if (fthree < sthree)
	{
		std::cout << "yes \n";
	}
	else if (fthree == sthree)
	{
		std::cout << "equal \n";
	}
	else
	{
		std::cout << "no \n";
	}

	return 0;
}