/*���.5
�������� ��������, ����� ������� ����������� �� ��� ����������.
    
���.5.1 ���������� �� �� �������� ������� ����������.

*/

#include <iostream>

int main()
{
	//���.5
	int a, b, swap;
	std::cin >> a >> b;
	
	swap = a;
	a = b;
	b = swap;

	std::cout << a << " and " << b<<"\n";

	//���.5.1
	int A, B;
	A = 4;
	B = 8;

	A = A + 4;
	B = B - 4;
	std::cout << A << " and " << B << "\n";


	return 0;
}