/*���.0
�������� ��������, ����� �� ������ ����������� �� ������, 
������� ����������� ����������� �� ���������.*/

#include <iostream>

int main()
{
	float tempC,tempF;
	std::cin >> tempC;

	tempF = (tempC*(1.8)) + 32;
	std::cout <<tempC<<" celsius is "<< tempF <<" in farenheit.\n";



	return 0;
}