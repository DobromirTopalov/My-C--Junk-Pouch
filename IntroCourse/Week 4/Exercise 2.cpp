/*���.2
���� ����� � ���������, ��� �� ��������� ��� ���� 2p - 1. �������� ��������, ����� ������ ���� ����������� ����� n � ������ 
������ ��������� ����� ��-����� �� n.*/

#include <iostream>
#include <cmath>

int main()
{
	int number;
	std::cin >> number;
	bool isOkay = true;
	
	int i = 0;
	while(isOkay)
	{
		if ((pow(2, i) - 1) < number)
		{
			std::cout << pow(2, i) - 1 << " ";
			i++;
		}
		else
		{
			isOkay = false;
		}
	}
	std::cout << "\n";


	return 0;
}