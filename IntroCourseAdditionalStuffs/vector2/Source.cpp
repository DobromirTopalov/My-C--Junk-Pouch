#include <iostream>
#include <vector>

void fillVector(std::vector<std::vector<int>>&neshto)
{
	for (int k = 0; k < neshto.size(); k++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cin >> neshto[k][j];
		}
	}

}


int main()
{
	std::vector <std::vector<int>>twoodvector(3, std::vector<int>(5));
	fillVector(twoodvector);
	std::cout << twoodvector[1][4]<<"\n";

	int* asd = new int;
	*asd = 69;
	std::cout << *asd;

	delete asd;
	std::cout << *asd;
	return 0;
}