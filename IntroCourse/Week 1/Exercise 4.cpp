/*���.4
�������� ��������, ����� ������ 3 ������ ����� - x, start � end � �������� ���� � ���� � ��������� [start, end].*/

#include <iostream>

int main()
{
	float x, start, end;
	std::cin >> x >> start >> end;
	if (x >= start && x <= end)
	{
		std::cout << "yes \n";
	}
	else
	{
		std::cout << "no \n";
	}


	return 0;
}