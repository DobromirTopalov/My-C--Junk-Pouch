/*���.1
�������� ��������, ����� ������ ���� ����� n, ���� ����� ������ n �� ���� ���� ����� � ��������� ���-�������� � ���-������� �� ���.*/


#include <iostream>


int main()
{
	int number;
	std::cin >> number;
	
	int min=0;
	int max=1;

	while (number>0)
	{
		int temp;
		std::cin >> temp;
		if (temp >= max)
		{
			max = temp;
		}
		else if (temp <= min)
		{
			min = temp;
		}
		number--;
	}
	std::cout << min << " and " << max << "\n";


	return 0;
}