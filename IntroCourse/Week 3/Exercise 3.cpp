/*���.3
�������� ��������, ����� ��������� ��-������� �� ��� ������ ���� ����� 7 ����, � ��-�������� ����� �������� � 23.*/

#include <iostream>

int main()
{
	int a, b;
	std::cin >> a >> b;

	if (a < b)
	{
		a *= 7;
		b -= 23;
	}
	else if (a > b)
	{
		a -= 23;
		b *= 7;
	}
	else
	{
		//do nothing
	}

	std::cout << a << " and " << b << "\n";
	
	return 0;
}