/*���.2
�� �� ������ ��������, � ����� ����������� ������� 3 ����� �� ������������ � ������� �� ������ ���- �������� �� ���.*/

#include <iostream>

int main()
{
	int one, two, three;
	std::cin >> one >> two >> three;

	if (one > two && one > three)
	{
		std::cout << one << "\n";
	}else if (one < two && two > three)
	{
		std::cout << two << "\n";
	}
	else if (one < three && two < three)
	{
		std::cout << three<<"\n";
	}
	else
	{
		std::cout << "There is not a greater number \n";
	}


	return 0;
}