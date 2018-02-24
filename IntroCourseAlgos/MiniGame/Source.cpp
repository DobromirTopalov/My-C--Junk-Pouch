#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void move(char movement, int rowofchar, int colofchar, char arr[][9]);
int main();

int mindmg = 7000;					//character's min dmg
int maxdmg = 23000;				//character's max dmg
int mindmgA = 4;				//computer's max dmg
int maxdmgA = 25;				//computer's max dmg
int mindmgB = 20;				//computer's max dmg
int maxdmgB = 38;				//computer's max dmg
int counter = 5;				//number of creatures to be killed to successfully finish a game
bool fail = false;				//value used to break everything

int getRandomNumber(int min, int max)		//rng for dmges,locations,stats,...
{
	srand((int)time(0));
	int r = (rand() % max) + min;
	return r;
}

void fillTerrain(int rows, int cols,char arr[][9])		//brute-forcing terrain
{
	for (int r = 0; r < rows; r++)
	{	
		for (int c = 0; c < cols; c++)
		{
			arr[r][c] = ' ';							//making blank spaces
		}
	}
	for (int r = 0; r < rows; r++)
	{
		if (r != 0 || r!=8)
		{
			arr[r][0] = '+';							//build side walls
			arr[r][8] = '+';
		}
		if (r == 0 || r == 8)
		{
			for (int c = 0; c < cols; c++)
			{
				arr[r][c] = '+';						//build top-bottom walls
			}
		}
	}
	arr[2][5] ='|';				//tree - character cannot move through the object ---> has to use alternative ways
	arr[3][2] = '|';
	arr[3][3] = '|';
	arr[6][2] = '|';
	arr[6][4] = '|';

	arr[1][6] = 'A';			//npc - character engages a fight with it (if survives-gains your hp back+2x attack points more And goes on till all npcs are killed)
	arr[3][3] = 'A';
	arr[4][2] = 'A';
	arr[6][6] = 'A';
	arr[6][5] = 'A';


	arr[3][7] = 'x';			//black hole-character dies instantly(hidden)
	arr[4][7] = 'x';

	arr[1][1] = ' ';			//water-character can swim only if the other side is land ' ' 
	arr[1][2] = '~';
	arr[2][1] = '~';
	arr[2][2] = '~';
	arr[3][1] = '~';
	arr[4][1] = '~';
	arr[5][1] = '~';
	arr[5][2] = '~';
	arr[5][3] = '~';
	arr[6][1] = '~';
	arr[7][1] = ' ';
	arr[7][2] = '~';
	arr[7][3] = '~';
	arr[7][4] = '~';

	arr[3][5] = '7';			//character symbol

	arr[7][7] = 'S';			//bonus buff-25% more dmg for the next 2 fights

	arr[1][7] = 'E';			//exit/finish

}
void showTerrain(int rows, int cols, char arr[][9])				//shows the changes of terrain during the play(like an animation)
{

	for (int r = 0; r < rows; r++)
	{
		std::cout << "		            ";
		for (int c = 0; c < cols; c++)
		{
			std::cout<< std::setw(2) <<arr[r][c];
		}
		std::cout << "\n";
	}
	std::cout <<"\n"<< "		       "<<"Your character is the symbol \'7\'"<<"\n";
	std::cout << "____________________________________________________________________________|";
}
void movekey(char arr[][9],int rowofchar,int colofchar)						//controls of character and special keys
{
		if (fail)
		{
			return;
		}
		else
		{
			char movement;
			MOVE:
			std::cin >> movement;
			if (movement == 'w' || movement == 'a' || movement == 's' || movement == 'd')
			{
				//check if allowed or not and conditions
				move(movement, rowofchar, colofchar, arr);
			}
			else
			{
				goto MOVE;	//nothing
			}
		}
}

int randombonus(int min, int max, int rowofchar, int colofchar, char arr[][9])				//bonuses
{
	int bonus;
	bonus=getRandomNumber(min, max);
	switch (bonus)
	{
	case 1:
		//revive all creatures
		arr[1][6] = 'A';
		arr[3][3] = 'A';
		arr[4][2] = 'A';
		arr[6][6] = 'A';
		arr[6][5] = 'A';
		std::cout << "All creatures has been recovered from death!!!\n"; break;
		return 1;

	case 2:
		//weaken your powers by 25%
		mindmg = mindmg - (mindmg*(25 / 100));
		maxdmg = maxdmg - (maxdmg*(25 / 100));
		std::cout << "You feel weak:-25% power reduction!!!\n"; break;
		return 2;

	case 3:
		//weaken creatures powers by 25%
		mindmgA = mindmgA - (mindmgA*(25 / 100));
		maxdmgA = maxdmgA - (maxdmgA*(25 / 100));
		std::cout << "All creatures are weakened:-25% power reduction!!!\n"; break;
		return 3;

	case 4:
		//you have another roll for bonus
		//randombonus(1,6,rowofchar,colofchar, arr); break;
		std::cout << "KUR\n";
		return 4;

	case 5:
		//summons a boss with ultimate powers
		arr[1][6] = ' ';
		arr[3][3] = 'A';
		arr[4][2] = ' ';
		arr[6][6] = ' ';
		arr[6][5] = ' ';
		mindmgA = mindmgB;
		maxdmgA = maxdmgB;
		std::cout << "BOSS AWAKEN!!!\n"; break;
		return 5;

	case 6:
		//you die of poison
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "GAME OVER ! ! ! \n";
		std::cout << "You die of poison ! ! ! \n";
		fail = true;break;

		return 6;
	}
}

void move(char movement,int rowofchar,int colofchar,char arr[][9])			//everything happens here-actions,effects,texts....	
{
	bool go = true;
	char buffer[1][1];
	if (movement == 'w')																							//forward							
	{
		if (arr[rowofchar - 1][colofchar] == '|')
		{
			std::cout << "There is a tree ahead,you cannot pass-use another path!\n";
			go = false;
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
		else if (arr[rowofchar - 1][colofchar] == '~')
		{
			int k = 1;
			int jump;
			while (arr[rowofchar - k][colofchar] == '~')
			{
				if ((arr[rowofchar - k - 1][colofchar] == '~')||(arr[rowofchar - k - 1][colofchar] == ' '))
				{
					go = true;
				}
				else
				{
					go = false;
					std::cout << "You cannot pass-use another path!\n";
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
				}
				jump = k;
				k++;
			}
			if (go)
			{
				buffer[0][0] = arr[rowofchar - 1][colofchar];
				arr[rowofchar - 1][colofchar] = buffer[0][0];
				arr[rowofchar - jump - 1][colofchar] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar - jump - 1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar - 1][colofchar] == ' ')
		{
			go = true;
			if (go)
			{
				buffer[0][0] = arr[rowofchar - 1][colofchar];
				arr[rowofchar - 1][colofchar] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = buffer[0][0];
				rowofchar = rowofchar - 1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar - 1][colofchar] == 'A')
		{
			go = true;
			if (go)
			{
				int hp = 370;
				int hpA = 400;
				int yourdmg = 0;
				int Admg = 0;
				char attack;
				
					while ((hp > 0) || (hpA > 0))
					{
						std::cout << "Press T for attack!";
						std::cin >> attack;
						std::cout << "\n\n";
						if (attack == 't')
						{
							std::cout << "You\'ve dmged rabbit for: ";
							yourdmg = getRandomNumber(mindmg, maxdmg);
							std::cout << yourdmg << "\n";
							std::cout << "Rabbit\'ve dmged you for: ";
							Admg = getRandomNumber(mindmgA, maxdmgA);
							std::cout << Admg << "\n";
							hp = hp - Admg;
							hpA = hpA - yourdmg;
							std::cout << "				" << "Your hp now is: " << hp << " and Rabbit\'s hp is: " << hpA << "\n\n";

							yourdmg = 0;
							Admg = 0;
						}
						if (hp <= 0 || hpA <= 0)
						{
							break;
						}
					}
				
				if (hp <= 0 && hpA>0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					//end of game!
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp <= 0 && hpA<=0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if(hp>0 &&hpA<=0)
				{
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					mindmg +=2;
					maxdmg +=2;
					counter--;
					buffer[0][0] = arr[rowofchar - 1][colofchar];
					arr[rowofchar - 1][colofchar] = arr[rowofchar][colofchar];
					arr[rowofchar][colofchar] = ' ';
					rowofchar = rowofchar - 1;
					colofchar = colofchar;
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
					go = false;
				}
			}
		}
		
	
		else if (arr[rowofchar - 1][colofchar] == 'E')
		{
			if (counter == 0)
			{
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";

				fail = true;
				movekey(arr, rowofchar, colofchar);
			}
			else
			{
				std::cout << "You have to kill all the creatures before you excape this dungeon\n";
				go = false;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar - 1][colofchar] == 'x')
		{
			
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "You step on a mine ! ! ! \n";
			go = false;
			fail = true;
			movekey(arr, rowofchar, colofchar);

			return;
			
		}
		else if (arr[rowofchar - 1][colofchar] == 'S')
		{
			randombonus(1, 6, rowofchar, colofchar, arr);
			if (fail)
			{
				return;
			}
			else
			{
				buffer[0][0] = arr[rowofchar - 1][colofchar];
				arr[rowofchar - 1][colofchar] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar - 1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}

		}
		else
		{
			go = false;
			std::cout << "You cannot pass-use another path!\n";		
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
	}

	if (movement == 's')																							//backward
	{
		if (arr[rowofchar + 1][colofchar] == '|')
		{
			std::cout << "There is a tree ahead,you cannot pass-use another path!\n";
			go = false;
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
		if (arr[rowofchar + 1][colofchar] == '~')
		{
			int k = 1;
			int jump;
			while (arr[rowofchar + k][colofchar] == '~')
			{
				if ((arr[rowofchar + k + 1][colofchar] == '~') || (arr[rowofchar + k + 1][colofchar] == ' '))
				{
					go = true;
				}
				else
				{
					go = false;
					std::cout << "You cannot pass-use another path!\n";
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
				}
				jump = k;
				k++;
			}
			if (go)
			{
				buffer[0][0] = arr[rowofchar + 1][colofchar];
				arr[rowofchar + 1][colofchar] = buffer[0][0];
				arr[rowofchar+jump+1][colofchar]=arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar +jump+1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		if (arr[rowofchar + 1][colofchar] == ' ')
		{
			go = true;
			if (go)
			{
				buffer[0][0] = arr[rowofchar + 1][colofchar];
				arr[rowofchar + 1][colofchar] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = buffer[0][0];
				rowofchar = rowofchar + 1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		
		else if (arr[rowofchar + 1][colofchar] == 'A')
		{
			go = true;
			if (go)
			{
				int hp = 370;
				int hpA = 400;
				int yourdmg = 0;
				int Admg = 0;
				char attack;

				while ((hp > 0) || (hpA > 0))
				{
					std::cout << "Press T for attack!";
					std::cin >> attack;
					std::cout << "\n\n";
					if (attack == 't')
					{
						std::cout << "You\'ve dmged rabbit for: ";
						yourdmg = getRandomNumber(mindmg, maxdmg);
						std::cout << yourdmg << "\n";
						std::cout << "Rabbit\'ve dmged you for: ";
						Admg = getRandomNumber(mindmgA, maxdmgA);
						std::cout << Admg << "\n";
						hp = hp - Admg;
						hpA = hpA - yourdmg;
						std::cout << "				" << "Your hp now is: " << hp << " and Rabbit\'s hp is: " << hpA << "\n\n";

						yourdmg = 0;
						Admg = 0;
					}
					if (hp <= 0 || hpA <= 0)
					{
						break;
					}
				}

				if (hp <= 0 && hpA>0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					//end of game!
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp <= 0 && hpA <= 0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp>0 && hpA <= 0)
				{
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					mindmg +=2;
					maxdmg +=2;
					counter--;
					buffer[0][0] = arr[rowofchar + 1][colofchar];
					arr[rowofchar + 1][colofchar] = arr[rowofchar][colofchar];
					arr[rowofchar][colofchar] = ' ';
					rowofchar = rowofchar + 1;
					colofchar = colofchar;
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
					go = false;
				}
			}
		}


		else if (arr[rowofchar + 1][colofchar] == 'E')
		{
			if (counter == 0)
			{
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";

				fail = true;
				movekey(arr, rowofchar, colofchar);
			}
			else
			{
				std::cout << "You have to kill all the creatures before you excape this dungeon\n";
				go = false;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar + 1][colofchar] == 'x')
		{

			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "You step on a mine ! ! ! \n";
			go = false;
			fail = true;
			movekey(arr, rowofchar, colofchar);

			return;

		}
		else if (arr[rowofchar + 1][colofchar] == 'S')
		{
			randombonus(1,6, rowofchar, colofchar, arr);
			if (fail)
			{
				return;
			}
			else
			{
				buffer[0][0] = arr[rowofchar + 1][colofchar];
				arr[rowofchar + 1][colofchar] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar + 1;
				colofchar = colofchar;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}

		}
		else
		{
			go = false;
			std::cout << "You cannot pass-use another path!\n";
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
	}

	if (movement == 'a')																							//leftside
	{
		if (arr[rowofchar][colofchar-1] == '|')
		{
			std::cout << "There is a tree ahead,you cannot pass-use another path!\n";
			go = false;
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
		else if (arr[rowofchar][colofchar - 1] == '~')
		{
			int k = 1;
			int jump;
			while (arr[rowofchar][colofchar - k] == '~')
			{
				if ((arr[rowofchar][colofchar - k - 1] == '~') || (arr[rowofchar][colofchar - k - 1] == ' '))
				{
					go = true;
				}
				else
				{
					go = false;
					std::cout << "You cannot pass-use another path!\n";
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
				}
				jump = k;
				k++;
			}
			if (go)
			{
				buffer[0][0] = arr[rowofchar][colofchar - 1];
				arr[rowofchar][colofchar - 1] = buffer[0][0];
				arr[rowofchar][colofchar - jump - 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar;
				colofchar = colofchar - jump - 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar - 1] == ' ')
		{
			go = true;
			if (go)
			{
				buffer[0][0] = arr[rowofchar][colofchar - 1];
				arr[rowofchar][colofchar - 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = buffer[0][0];
				rowofchar = rowofchar;
				colofchar = colofchar - 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar - 1] == 'A')
		{
			go = true;
			if (go)
			{
				int hp = 370;
				int hpA = 400;
				int yourdmg = 0;
				int Admg = 0;
				char attack;

				while ((hp > 0) || (hpA > 0))
				{
					std::cout << "Press T for attack!";
					std::cin >> attack;
					std::cout << "\n\n";
					if (attack == 't')
					{
						std::cout << "You\'ve dmged rabbit for: ";
						yourdmg = getRandomNumber(mindmg, maxdmg);
						std::cout << yourdmg << "\n";
						std::cout << "Rabbit\'ve dmged you for: ";
						Admg = getRandomNumber(mindmgA, maxdmgA);
						std::cout << Admg << "\n";
						hp = hp - Admg;
						hpA = hpA - yourdmg;
						std::cout << "				" << "Your hp now is: " << hp << " and Rabbit\'s hp is: " << hpA << "\n\n";

						yourdmg = 0;
						Admg = 0;
					}
					if (hp <= 0 || hpA <= 0)
					{
						break;
					}
				}

				if (hp <= 0 && hpA>0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					//end of game!
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp <= 0 && hpA <= 0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp>0 && hpA <= 0)
				{
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					mindmg +=2;
					maxdmg +=2;
					counter--;
					buffer[0][0] = arr[rowofchar][colofchar - 1];
					arr[rowofchar][colofchar - 1] = arr[rowofchar][colofchar];
					arr[rowofchar][colofchar] = ' ';
					rowofchar = rowofchar;
					colofchar = colofchar-1;
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
					go = false;
				}
			}
		}


		else if (arr[rowofchar][colofchar - 1] == 'E')
		{
			if (counter == 0)
			{
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";

				fail = true;
				movekey(arr, rowofchar, colofchar);
			}
			else
			{
				std::cout << "You have to kill all the creatures before you excape this dungeon\n";
				go = false;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar-1] == 'x')
		{

			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "You step on a mine ! ! ! \n";
			go = false;
			fail = true;
			movekey(arr, rowofchar, colofchar);

			return;

		}
		else if (arr[rowofchar][colofchar - 1] == 'S')
		{
			randombonus(1, 6, rowofchar, colofchar, arr);
			if (fail)
			{
				return;
			}
			else
			{
				buffer[0][0] = arr[rowofchar][colofchar - 1];
				arr[rowofchar][colofchar - 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar;
				colofchar = colofchar - 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}

		}
		
		else
		{
			go = false;
			std::cout << "You cannot pass-use another path!\n";
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
	}

	if (movement == 'd')																							//rightside
	{
		if (arr[rowofchar][colofchar + 1] == '|')
		{
			std::cout << "There is a tree ahead,you cannot pass-use another path!\n";
			go = false;
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
		else if (arr[rowofchar][colofchar + 1] == '~')
		{
			int k = 1;
			int jump;
			while (arr[rowofchar][colofchar + k] == '~')
			{
				if ((arr[rowofchar][colofchar + k + 1] == '~') || (arr[rowofchar][colofchar + k + 1] == ' '))
				{
					go = true;
				}
				else
				{
					go = false;
					std::cout << "You cannot pass-use another path!\n";
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
				}
				jump = k;
				k++;
			}
			if (go)
			{
				buffer[0][0] = arr[rowofchar][colofchar + 1];
				arr[rowofchar][colofchar + 1] = buffer[0][0];
				arr[rowofchar][colofchar + jump + 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar;
				colofchar = colofchar + jump + 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar + 1] == ' ')
		{
			go = true;
			if (go)
			{
				buffer[0][0] = arr[rowofchar][colofchar + 1];
				arr[rowofchar][colofchar + 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = buffer[0][0];
				rowofchar = rowofchar;
				colofchar = colofchar + 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar + 1] == 'A')
		{
			go = true;
			if (go)
			{
				int hp = 370;
				int hpA = 400;
				int yourdmg = 0;
				int Admg = 0;
				char attack;

				while ((hp > 0) || (hpA > 0))
				{
					std::cout << "Press T for attack!";
					std::cin >> attack;
					std::cout << "\n\n";
					if (attack == 't')
					{
						std::cout << "You\'ve dmged rabbit for: ";
						yourdmg = getRandomNumber(mindmg, maxdmg);
						std::cout << yourdmg << "\n";
						std::cout << "Rabbit\'ve dmged you for: ";
						Admg = getRandomNumber(mindmgA, maxdmgA);
						std::cout << Admg << "\n";
						hp = hp - Admg;
						hpA = hpA - yourdmg;
						std::cout << "				" << "Your hp now is: " << hp << " and Rabbit\'s hp is: " << hpA << "\n\n";

						yourdmg = 0;
						Admg = 0;
					}
					if (hp <= 0 || hpA <= 0)
					{
						break;
					}
				}

				if (hp <= 0 && hpA>0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					//end of game!
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp <= 0 && hpA <= 0)
				{
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					std::cout << "GAME OVER ! ! ! \n";
					fail = true;
					movekey(arr, rowofchar, colofchar);

					return;
				}
				if (hp>0 && hpA <= 0)
				{
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					std::cout << "Victory...+2AP-Move now!\n";
					mindmg +=2;
					maxdmg +=2;
					counter--;
					buffer[0][0] = arr[rowofchar][colofchar + 1];
					arr[rowofchar][colofchar + 1] = arr[rowofchar][colofchar];
					arr[rowofchar][colofchar] = ' ';
					rowofchar = rowofchar;
					colofchar = colofchar + 1;
					showTerrain(9, 9, arr);
					movekey(arr, rowofchar, colofchar);
					go = false;
				}
			}
		}


		else if (arr[rowofchar][colofchar + 1] == 'E')
		{
			if (counter == 0)
			{
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";
				std::cout << "Huurrrreeeyyyy!You are now a true GOPNIK!\n";

				fail = true;
				movekey(arr, rowofchar, colofchar);
			}
			else
			{
				std::cout << "You have to kill all the creatures before you excape this dungeon\n";
				go = false;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}
		}
		else if (arr[rowofchar][colofchar+1] == 'x')
		{

			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "GAME OVER ! ! ! \n";
			std::cout << "You step on a mine ! ! ! \n";
			go = false;
			fail = true;
			movekey(arr, rowofchar, colofchar);

			return;

		}

		else if (arr[rowofchar][colofchar + 1] == 'S')
		{
			randombonus(1, 6, rowofchar, colofchar, arr);
			if (fail)
			{
				return;
			}
			else
			{
				buffer[0][0] = arr[rowofchar][colofchar + 1];
				arr[rowofchar][colofchar + 1] = arr[rowofchar][colofchar];
				arr[rowofchar][colofchar] = ' ';
				rowofchar = rowofchar;
				colofchar = colofchar + 1;
				showTerrain(9, 9, arr);
				movekey(arr, rowofchar, colofchar);
			}

		}
		else
		{
			go = false;
			std::cout << "You cannot pass-use another path!\n";
			showTerrain(9, 9, arr);
			movekey(arr, rowofchar, colofchar);
		}
	}
}
int main()			//RUN.exe
{
	if (fail)
	{
		return 0;
	}
	else
	{

		char terrain[9][9];
	
		std::cout << "Welocme to GOPNIK\'s life!You can move with W,A,S,D ! GOOD LUCK !\n\n\n";
		fillTerrain(9, 9, terrain);
		showTerrain(9, 9, terrain);

		int rowofchar = 3;
		int colofchar = 5;
		movekey(terrain, rowofchar, colofchar);
	
		std::cout << "\n";
	}

	return 0;
}