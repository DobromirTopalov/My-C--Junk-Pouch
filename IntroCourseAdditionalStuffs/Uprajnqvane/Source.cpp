#include <iostream>
#include "Header.h"

int main()
{
	Rooms hol(4,15,3);
	Rooms spalnq (1, 7, 4);
	Rooms kuhnq=spalnq;


	std::cout << hol.getL() << " :hol\n";
	std::cout << spalnq.getL() << " :spalnq\n";
	std::cout << kuhnq.getL() << " :kuhnq\n";

	kuhnq=spalnq+hol;
	std::cout << kuhnq.getL() << " :kuhnq\n";
	std::cout <<"------------------------------------------------------------------\n";

	kuhnq = spalnq*hol;
	std::cout << kuhnq.getL() << " :kuhnq\n";

	kuhnq = hol / spalnq;
	std::cout << kuhnq.getL() << " :kuhnq\n";
	std::cout << "------------------------------------------------------------------\n";


	std::cout << (hol < spalnq) << " da<ne \n";
	std::cout << (hol > spalnq) << " da<ne \n";
	std::cout << (hol == spalnq) << " da<ne \n";
	Rooms koridor(8, 7, 6, 5, 4);
	std::cout << koridor[2]<<" gg\n";
	koridor(23,45,12);
	std::cout << koridor.getL() << " :kuhnq\n";
	std::cout << "------------------------------------------------------------------\n";

	std::cout << koridor.getW() << "\n";
	std::cout << koridor->getW() << "\n";

	return 0;
}