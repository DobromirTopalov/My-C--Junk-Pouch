/*���.4
�� �� �������� ���� ���� ������� �� ������ ���������� ����� ���� ��������� ��.*/

#include <iostream>

int main()
{
	int number, digitF, digitS, digitT;
	std::cin >> number;

	digitF = number / 100;
	digitS = ((number / 10) % 10);
	digitT = number % 10;

	if (digitT==digitS || digitS == digitF || digitT == digitF)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}

	return 0;
}