/*���.5
�� �� ������ ����������� ������� � ��������� n � k, ����� ������ ������ �����, ����� �� �������� �� ������������� ���� ����� n ����
�� �������� k����� �� ������� ������ �����.
�������� ��� n � 31245 � k � 4, ��������� ������ �� ������ ������� 3245; ��� k � 2, ��������� ������ �� ������ ������� 3125,
� ��� n � 5 � k � 1, ��������� ������ �� ������ ������� 0.*/

#include <iostream>
#include <cmath>

int rewriteNum(int num, int n)
{
	int digits = (int)log10((double)abs(num) + 1);
	if (digits == 0 && n == 1)
	{
		return 0;
	}
	int cock = 1;
	int tail = 1;

	tail = num % (int)(pow(10, n - 1));
	cock = (num / (int)(pow(10, n)))*(pow(10,n-1));
	
	int newnum = cock+tail;

	return newnum;
}


int main()
{
	int n, k;
	std::cin >> n >> k;
	std::cout << rewriteNum(n, k) << "\n";

	return 0;
}