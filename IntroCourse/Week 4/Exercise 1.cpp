/*«ад.1
Ќапишете програма, ко€то приема ц€ло число n, след което приема n на брой цели числа и отпечатва най-гол€мото и най-малкото от т€х.*/


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