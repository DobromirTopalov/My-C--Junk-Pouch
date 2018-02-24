#include <iostream>
#include <cstring>

int horizontal = 5;
int vertical = 5;
char replaceSymbol = 'X';


void fill(char** list)
{
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			std::cin >> list[i][j];
			if ((list[i][j]>='A')&&(list[i][j]<='Z'))
			{
				//ok
			}
			else
			{
				std::cout << "Incorrect input!\n";
				return;
			}
		}
	}
}

int validate(char** list,int hor,int ver)
{
	if (list[hor][ver] == list[hor][ver-1])
	{
		return 0;
	}
	else if (list[hor][ver] == list[hor][ver + 1])
	{
		return 0;
	}
	else if (list[hor][ver] == list[hor - 1][ver])
	{
		return 0;
	}
	else if (list[hor][ver] == list[hor + 1][ver])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

char* replacer(char** list,char** arr)
{
	bool what = false;
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			if (list[i][j] == 'X')
			{
				replaceSymbol = 'X';
				what=true;
				break;
			}
			else
			{
				replaceSymbol = 'Z';				
			}
		}
		if (what)
		{
			break;
		}
	}
	char* newchar = new char[1];
	for (int p = 0; p < 1; p++)
	{
		newchar[p] = replaceSymbol;
	}
	newchar[1] = '\0';
	
	*arr = newchar;
	newchar = nullptr;
	return *arr;
}

void printText(char* text)
{
	for (int i = 0; text[i] != '\0'; i++)
	{
		std::cout << text[i];
	}
}

void format(char text[],char symbol)
{
	for (int i = 0; text[i] !='\0'; i++)
	{
		if ((text[i] >= 'a') && (text[i] <= 'z'))
		{
			text[i] = text[i] - 32;
		}
		if ((!((text[i] >= 'a') && (text[i] <= 'z')))&& (!((text[i] >= 'A') && (text[i] <= 'Z'))))
		{
			text[i] = replaceSymbol;
		}
	}
}


bool isinHorizontal(char**list,char one,char two)
{
	bool firstword = false;
	bool secondword = false;
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			
			if ((one == list[i][j]))
			{
				firstword = true;
			}
		
			if ((two == list[i][j]))
			{
				secondword = true;
			}
		}
		if (firstword&&secondword)
		{
			return true;
			break;
		}
		else
		{
			firstword = false;
			secondword = false;
			continue;
		}
	}
	return false;
}

bool isinVertical(char**list, char one, char two)
{
	bool firstword = false;
	bool secondword = false;
	
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			if ((one == list[j][i]))
			{
				firstword = true;
			}

			if ((two == list[j][i]))
			{
				secondword = true;
			}
		}
		if (firstword&&secondword)
		{
			return true;
			break;
		}
		else
		{
			firstword = false;
			secondword = false;
			continue;
		}
	}
	return false;
}


void seekNdestroyH(char text[],char** list, int indexone, int indextwo)
{
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			if ((text[indexone] == list[i][j]))
			{
				if ((j + 1) == vertical)
				{
					text[indexone] = list[i][0];
					break;
				}
				else
				{
					text[indexone] = list[i][j + 1];
					break;
				}
			}
		}
		for (int j = 0; j < vertical; j++)
		{
			if ((text[indextwo] == list[i][j]))
			{
				if ((j + 1) == vertical)
				{
					text[indextwo] = list[i][0];
					break;
				}
				else
				{
					text[indextwo] = list[i][j+1];
					break;
				}
			}
		}
	}
}


void seekNdestroyV(char text[], char** list, int indexone, int indextwo)
{
	for (int i = 0; i < vertical; i++)
	{
		for (int j = 0; j < horizontal; j++)
		{
			if ((text[indexone] == list[j][i]))
			{
				if (j + 1 == horizontal)
				{
					text[indexone] = list[0][i];
					break;
				}
				else
				{
					text[indexone] = list[j+1][i];
					break;
				}
			}
		}
		for (int j = 0; j < horizontal; j++)
		{
			if ((text[indextwo] == list[j][i]))
			{
				if (j + 1 == horizontal)
				{
					text[indextwo] = list[0][i];
					break;
				}
				else
				{
					text[indextwo] = list[j+1][i];
					break;
				}
			}
		}
	}
}

void seekNdestroy(char text[], char** list, int indexone, int indextwo)
{
	int h1, v1, h2, v2;
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			if ((text[indexone] == list[i][j]))
			{
				h1 = i;
				v1 = j;
			}
		}
	}
	for (int i = 0; i < horizontal; i++)
	{
		for (int j = 0; j < vertical; j++)
		{
			if ((text[indextwo] == list[i][j]))
			{
				h2 = i;
				v2 = j;
			}
		}
	}
	
	if ((h1 < h2)&&(v1<v2))
	{
		text[indexone] = list[h1][v2];
		text[indextwo] = list[h2][v1];
	}
	else if((h1>h2)&&(v1>v2))
	{
		text[indexone] = list[h1][v2];
		text[indextwo] = list[h2][v1];
	}
	else if ((h1<h2) && (v1>v2))
	{
		text[indexone] = list[h1][v2];
		text[indextwo] = list[h2][v1];
	}
	else if ((h1>h2) && (v1<v2))
	{
		text[indexone] = list[h1][v2];
		text[indextwo] = list[h2][v1];
	}
	
}

void code(char* text, char** list)
{
	for (int i = 0; text[i] != '\0'; i+=2)
	{
		if (text[i] == text[i + 1])
		{
			if ((text[i] == replaceSymbol) && (text[i + 1] == replaceSymbol))
			{
				continue;
			}
			else
			{
				text[i + 1] = replaceSymbol;
				std::cout <<"\n_>"<< replaceSymbol<<"<_\n";
			}
		}
		if (isinHorizontal(list, text[i], text[i + 1]))
		{
			seekNdestroyH(text,list,i,i+1);
		}
		if (isinVertical(list, text[i], text[i + 1]))
		{
			seekNdestroyV(text, list, i, i + 1);
		}

		if ((!(isinVertical(list, text[i], text[i + 1]))) && (!(isinHorizontal(list, text[i], text[i + 1]))))
		{
			seekNdestroy(text, list, i, i + 1);
		}

	}
}


int main()
{
	char** list = new char*[horizontal];
	for (int i = 0; i < horizontal; i++)
	{
		list[i] = new char[vertical];
	}
	fill(list);
	char* text = new char[100000];
	std::cout << "Enter text: ";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.getline(text, 100000);


	int length = strlen(text);
	char* replace = new char[1];
	
	replacer(list,& replace);
	
	if (length % 2 != 0)
	{
		strcat(text,replace);
	}
	
	format(text, replaceSymbol);
	code(text, list);
	printText(text);
	std::cout << "\n";
	


	return 0;
}