#include <iostream>

void chainOFNumbers(int memberOFChain)
{

	if (memberOFChain == 1)
	{
		std::cout << memberOFChain;
	}
	else
	{
		chainOFNumbers(memberOFChain - 1);
		std::cout << memberOFChain;
		chainOFNumbers(memberOFChain - 1);
	}

}

int main()
{
	int member;
	std::cin >> member;

	if (member > 0 && member < 20)
	{
		chainOFNumbers(member);
		std::cout << "\n";
	}

	return 0;
}