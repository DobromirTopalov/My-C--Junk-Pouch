/*���.0
�� �� ������ �������, ����� ������ ���� ��������� �� ��� int � ����� ������� ��������� � 1.*/

#include <iostream>

int increase(int n)
{
	return ++n;
}

int main()
{
	int n;
	std::cin >> n;
	std::cout << increase(n) << "\n";


	return 0;
}