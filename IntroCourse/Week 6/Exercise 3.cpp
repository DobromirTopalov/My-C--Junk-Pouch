/*���.3
�� �� ������ �������, ����� ������ ���������� ����� ���� ��������� � ����� ������� �� �������� � ������� ����� ���� �����.*/

#include <iostream>

int fibonum(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (num == 1)
	{
		return 1;
	}
		return fibonum(num-2) + fibonum(num - 1);
}

int main()
{
	int num;
	std::cin >> num;
	
	std::cout << fibonum(num)<<"\n";

	return 0;
}