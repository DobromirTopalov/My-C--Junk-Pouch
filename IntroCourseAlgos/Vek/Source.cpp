#include <iostream>								//���� ������� ������������ <iostream> �� ����/�����(������) �� �����
												//��� ������ �� �������� �� ������������.���� ��� ��� ����� �������
												//������ ����� ���(� ������ �� iostream) � �� ������(include)
												//� ������ �������� ���� ��� ���� ���.

int main()										//�������,����� ��������� ��� ���������� � � ����� �� �� ������� �� ���,�.� main ����
{												//��������/������ �� ���������� (���� ������� � ����� ��� ����� � �������� ������� �����)
												//���� ���� ��� �������� ����� �������,�� �� ���� ������ ��������� ����� �� ����� ��� ����
												//�� main ���������

	int year;									//�������� ���������� �� ����� ��� - ��������� ������ � ������� �� ���������	
	std::cout << "Enter a year: ";				//������� �� ������ ��������� � ��������� ("cout" ���� �� "console output")

	std::cin >> year;							//������� ��� �����,� ������, �� ������������ ����������

	if (year >= 2001 && year <= 2100)			//������ �������,����� ��� � ������� �� ��������� ���� � ����� ��� ����,� ��������
	{											//������ ��������� else-�����.����� ������� &&(��������� "�") � ������� �� ��������
												//"��� ���� �����" � "���� ���� �����" �� �������� �����(true) ,�� ������ "����� ����� � true"
												//� �� ��������� ����� � if-�����,��� �  false - �� ��������� else-�����.
		std::cout << "The year " << year << " is in 21century! \n";
	}
	else
	{
		std::cout << "Year "<<year<<" is not in 21century! \n";
	}

	return 0;									//��������� �� ����� �� ��� ����,������ ,�� ����� �� ������ �� ������ �������� � ������,�� �����-��
												//������� �� (int,bool,float,double,unsigned...���� ������)
												//������� �� (void-�� ������ ����)
												//��� � �������� return 0; ,�� �� �� ������,�� ������ � �������.(��� main ���� ��� ���� �� �� ��������)
												//��� ���� ����������� ���/������ �� �� ������ return-a.
}