/*���.12
�������� ��������, ����� ��������� ���� ������ ���������� ����� �� ���� �� 3
    -���� ��������� �������� �� �������
    -���� ������� �� �������� �� 3
*/

#include <iostream>

int main()
{
	int number;
	std::cin >> number;
	bool check(number % 3 == 0);
	std::cout <<std::boolalpha << check <<"\n";

	///////////////////////////////////////////////////

	int sum;
	sum = (number / 100) + ((number / 10) % 10) + (number % 10);
	if (sum % 3 == 0)
	{
		std::cout << "yes\n";
	}
	else
	{
		std::cout << "no\n";
	}
	
	return 0;
}