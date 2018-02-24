#include <iostream>

const unsigned int STATS = 4;
const unsigned short TSIZE = 1;

void fill(int** list,int numberOfPlans)
{
	for (int i = 0; i < numberOfPlans; i++)
	{
		for (int k = 0,p=1; k < STATS; k++,p++)
		{
			std::cin >> list[i][k];
		}
	}
}

bool validate(int** list, int numberOfPlans)
{
	for (int i = 0; i < numberOfPlans; i++)
	{
		for (int k = 0, p = 1; k < STATS; k++, p++)
		{
			if (!((list[i][0] >= 0) && (list[i][0] <= 1000)))
			{
				return false;
			}
			if (!((list[i][p] >= 0) && (list[i][p] <= 100000)))
			{
				return false;
			}
		}
	}
	return true;
}

void fillTraffic(int** list)
{
	for (int i = 0; i < TSIZE; i++)
	{
		list[i][0]=0;
		for (int k = 1; k < STATS; k++)
		{
			std::cin >> list[i][k];
		}
	}
}

void print(int** list, int numberOfPlans)
{
	for (int i = 0; i < numberOfPlans; i++)
	{
		for (int k = 0; k < STATS-1; k++)
		{
			std::cout << list[i][k] << " ";
		}
		std::cout << list[i][STATS - 1] << "\n";
	}
}

int search(int** listOne, int** listTwo, int numberOfPlans)
{
	int counter = 0;

	for (int i = 0, k = 1, p = 2, j = 3; i < numberOfPlans; i++)			//keep track of how many of the plans match the traffic
	{
		if ((listOne[i][k] >= listTwo[0][k]) && (listOne[i][p] >= listTwo[0][p]) && (listOne[i][j] >= listTwo[0][j]))
		{
			counter++;
		}
	}
	return counter;
}

void search(int** listOne, int** listTwo, int** listThree, int numberOfPlans)
{
	int index = 0;

	for (int i = 0, k = 1, p = 2, j = 3; i < numberOfPlans; i++)
	{
		if ((listOne[i][k] >= listTwo[0][k]) && (listOne[i][p] >= listTwo[0][p]) && (listOne[i][j] >= listTwo[0][j]))
		{
			for (int no = 0; no < STATS; no++)
			{
				listThree[index][no] = listOne[i][no];
			}
			++index;

		}
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void sortList(int** list, int numberOfPlans)
{
	int biggest = 0;
	for(int i=0;i<numberOfPlans;i++)
	{
		biggest = i;
		for (int n = i; n < numberOfPlans; n++)
		{
			if (list[biggest][0] < list[n][0])
			{
				biggest = n;
			}
		}
		if (biggest != i)
		{
			for (int j = biggest; j > i; j--)
			{

				swap(list[j][0], list[j - 1][0]);
				swap(list[j][1], list[j - 1][1]);
				swap(list[j][2], list[j - 1][2]);
				swap(list[j][3], list[j - 1][3]);

			}
		}
	}
}

int main()
{
	unsigned int numberOfPlans = 0;

	std::cout << "Enter the total number of mobile plans of your mobile operator: ";
	std::cin >> numberOfPlans;
	if ((numberOfPlans < 100000)&&(numberOfPlans>0))
	{

		int** plans = new int*[numberOfPlans];
		for (int i = 0; i < numberOfPlans; ++i)
		{
			plans[i] = new int[STATS];
		}

		int** traffic = new int*[TSIZE];
		for (int i = 0; i < TSIZE; ++i)
		{
			traffic[i] = new int[STATS];
		}
		
		std::cout << "Enter plans specifications in this order (price/min/mb/SMS): ";
		fill(plans, numberOfPlans);
		bool isValid = true;;
		if (isValid)
		{

			std::cout << "Enter your current traffic (min/mb/SMS): ";
			fillTraffic(traffic);

			int isOkay = search(plans, traffic, numberOfPlans);
			bool isAlright = false;
			if (isOkay)
			{
				isAlright = true;
			}

			if (isAlright)
			{
				int** solutions = new int*[isOkay];
				for (int i = 0; i < isOkay; ++i)
				{
					solutions[i] = new int[STATS];
				}

				search(plans, traffic, solutions, numberOfPlans);
				sortList(solutions, isOkay);
				print(solutions, isOkay);
			}
			else
			{
				std::cout << "Your mobile operator does not offer any specific plans for your needs!Have a nice day!\n";
			}
		}
	}
	else
	{
		std::cout << "Your mobile operator does not offer any specific plans for your needs!Have a nice day!\n";
	}

	return 0;
}