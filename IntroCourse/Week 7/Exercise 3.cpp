/*���.3
�� �� ������� �������� �� C++, ���� ����� �� �������� ������� � ������ ����� �� �������� �� ����� ��� ��� �������� ����������������
(���������� �� �����).*/

#include <iostream>

void draw (int a, int b)
{
	for (int i = a; i <= (b); i++)
	{
		for (int j = a; j < i+1; j++)
		{
			std::cout << j << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	int a, b;
	std::cin >> a >> b;

	draw(a,b);
	return 0;
}