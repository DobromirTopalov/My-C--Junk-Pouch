/*«ад.2
Ќапишете програма, ко€то приема координатите на точка от равнината и извежда на кой квадрант принадлежи т€. 
јко точката принадлежи на повече от един квадрант (т.е. е върху поне една от координатните оси) да се изведат 
всички квадранти, на които принадлежи точката.*/

#include <iostream>

int main()
{
	int x, y;
	std::cin >> x >> y;

	if (x > 0 && y > 0)
	{
		std::cout << "I quadrant!\n";
	}
	else if (x > 0 && y < 0)
	{
		std::cout << "IV quadrant!\n";
	}
	else if (x < 0 && y < 0)
	{
		std::cout << "III quadrant!\n";
	}
	else if (x < 0 && y>0)
	{
		std::cout << "II quadrant!\n";
	}
	else if (x==0 && y==0)
	{
		std::cout << "ALL quadrants!\n";
	}
	else if(x==0 && y>0)
	{
		std::cout << "I and II quadrants!\n";
	}
	else if (x > 0 && y == 0)
	{
		std::cout << "I and III quadrants!\n";
	}
	else if (x == 0 && y < 0)
	{
		std::cout << "III and IV quadrants!\n";
	}
	else if (x < 0 && y == 0)
	{
		std::cout << "II and III quadrants!\n";
	}
	else
	{
		std::cout << "Something went wrong!\n";
	}


	return 0;
}