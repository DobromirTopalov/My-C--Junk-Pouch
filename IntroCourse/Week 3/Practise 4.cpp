/*���.4

� ������ ������� ����� �� �������� ������ �� 52 �����. �� �� ����������� �� ����� ����� ������: 2, 3, 4, 5, 6, 7 ,8, 9, 10,
����, ����, ��� � ���. ����� �� ��� ��� 4 �������������: ������, ����, ���� � ����. �� �� ������� ��������, ����� ��� ��������� 
�� ���������� ����� �� ��������� [[1 - 52] ������� ������� ����� �� ��������.*/

#include <iostream>

int main()
{
	int card;
	std::cin >> card;
	
	if (card >= 1 && card <= 52)
	{
		
		int cardKind = ((card - 1) % 13) + 2;		//+2 because cards are 2,3,4,5....10 J Q K.. //(card-1) because if card=2 its 1%13=1 and 
		if (cardKind >= 2 && cardKind <= 10)		// 1+2=3 and we cannot get the 2s then we have to use (card-1) to ever have the chance to
		{											//get 2s
			std::cout << cardKind;
		}
		else
		{
			switch (cardKind)
			{
			case 11: std::cout << "J"; break;
			case 12: std::cout << "Q"; break;
			case 13: std::cout << "K"; break;
			case 14: std::cout << "A"; break;
			default:	break;
			}
		}

		int cardColor = ((card - 1) / 13) + 1;
		switch (cardColor)
		{
			case 1: std::cout << "Club"; break;
			case 2: std::cout << "Diamond"; break;
			case 3: std::cout << "Heart"; break;
			case 4: std::cout << "Spade"; break;
			default:	break;
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Bad input!\n";
	}


	return 0;
}