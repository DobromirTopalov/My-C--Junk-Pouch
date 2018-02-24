/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Dobromir Topalov
* @idnumber 45273
* @task 1C
* @compiler VC
*
*/


#include <iostream>
//#include <random>
#include <cstdlib>
#include <ctime>

int randomNumber(int low = 0, int high = 1);
int luckChance(int luckStats, int action);
void hpAfterFight(int dmgOfOpponent, int dmgOfUnit, int armorOfUnit, int armorOfOpponent, int& hpOfUnit, int&hpOfOpponent, int luckStatsOfUnit, int luckStatsOfOpponent, int actionUnit, int actionOpponent);

int main()
{
	bool playGame = true;									//game runs untill player press Exit or N(if dead)
	
	do														//be sure to run once at least
	{
		std::cout << "Four years have passed since the mortal races ... \n";
		std::cout << "					      ... the drums of war thunder once again \n\n";
		std::cout << "Press I - show stats | A - attack | D - defense | P - use potion | X - exit game \n";

		int playerHp = 100;						//resets all stats in case player dies and choose to run again
		int playerDmg = 10;
		int playerArmor = 25;
		int playerLuck = 5;
		int playerPotion = 5;


		char playerAction;						//actions of player
		int creaturesKilled = 0;				//counts kills, using this to increase stats of creatures and check if player has free game
		int tempPlayerHp = playerHp;			//need it for the 'fights' later
		int freeGames = 0;						//number of free games
		float bitCoins = 0;						//number of coins in pocket

		int creatureHp = 50;					//creature stats
		int creatureDmg = 5;
		int creatureArmor = 5;
		int creatureLuck = 0;

		std::cout << "Players starts with: " << playerHp << " hp. Creature starts with: " << creatureHp << " hp.\n";

		while (playerHp > 0 )					//kill and chill while you have hp
		{

			if (creatureHp > 0)
			{
				std::cout << "Take action! \n";
				std::cin >> playerAction;						//getting player action
				if ( !(playerAction == 'A' || playerAction == 'D' || playerAction == 'I' || playerAction == 'P' || playerAction == 'X') )
				{
					std::cout << "Invalid command!Choose again: \n";
					continue;
				}
				

				switch (playerAction)							//check what action player has chosen
				{
					int creatureAction;

					// show stats
					case 'I': std::cout << "Your current stats are: "
						<< "Health: " << playerHp
						<< ",Damage: " << playerDmg
						<< ",Armor: " << playerArmor
						<< ",Luck: " << playerLuck
						<< ",Potions: " << playerPotion << "\n"; break;

					//Attack			+ block of code in switch case
					case 'A':			
					{
						std::cout << "Player attacks! and ";

						creatureAction = randomNumber();												//Creature AI
						if (creatureAction)
						{
							std::cout << "Creature attacks! \n";
							hpAfterFight(playerDmg, creatureDmg, creatureArmor, playerArmor, creatureHp, playerHp, creatureLuck, playerLuck, 1, 1);
						}
						else
						{
							std::cout << "Creature did a defense! \n";
							hpAfterFight(playerDmg, creatureDmg, creatureArmor, playerArmor, creatureHp, playerHp, creatureLuck, playerLuck,0,1);			//playerHpAfter
						}

						if (playerHp <= 0)
						{
							playerHp = 0;
						}
						if (creatureHp <= 0)
						{
							creatureHp = 0;
						}
						std::cout << "Player has| " << playerHp << " hp.\nCreature has| " << creatureHp << " hp. \n";
					}
					break;

					//Defense
					case 'D':
					{
						std::cout << "Player did a defense! and ";

						creatureAction = randomNumber();
						if (creatureAction)
						{
							std::cout << "Creature attacks! \n";
							hpAfterFight(playerDmg, creatureDmg, creatureArmor, playerArmor, creatureHp, playerHp, creatureLuck, playerLuck,1,0);			//playerHpAfter	
						}
						else
						{
							std::cout << "Creature did a defense! \n";
						}
						if (playerHp <= 0)
						{
							playerHp = 0;
						}
						if (creatureHp <= 0)
						{
							creatureHp = 0;
						}
						std::cout << "Player has| " << playerHp << " hp. \nCreature has| " << creatureHp << " hp. \n";
					}
					break;

					//Potions
					case 'P':
					{
						if (playerPotion > 0)									//if player still has potions left
						{
							std::cout << "Player used a potion! and ";
							playerHp = tempPlayerHp;							//tempPlayerHp stores player total HP before each fight
							playerPotion--;
						}
						else
						{
							std::cout << "Player's potion pouch is empty!No hp restored! and ";
						}

						creatureAction = randomNumber();
						if (creatureAction)
						{
							std::cout << "Creature attacks! \n";
							hpAfterFight(playerDmg, creatureDmg, creatureArmor, playerArmor, creatureHp, playerHp, creatureLuck, playerLuck, 1, 0);				//playerHpAfter
						}
						else
						{
							std::cout << "Creature did a defense! \n";
						}

						if (playerHp <= 0)
						{
							playerHp = 0;
						}
						if (creatureHp <= 0)
						{
							creatureHp = 0;
						}
						std::cout << "Player has| " << playerHp << " hp. \nCreature has| " << creatureHp << " hp. \n";
					}
					break;

					case 'X': std::cout << "You have exited the game! \n"; return 0; break;
				}
			}

			// if creature got killed
			else
			{
					std::cout << "\n\nPlayer have successfully killed the Creature! \n";
					
					//kill bonuses
					creaturesKilled++;
					playerHp = tempPlayerHp;						//reset player hp to maximum
					freeGames = creaturesKilled / 100;				//count free games
					bitCoins += 1 / 5;								//earn bitCoins per kill
					
					//loot corpse for potions
					bool isLoot = (bool)randomNumber();
					if (isLoot)
					{
						playerPotion++;
						std::cout << "Creature dropped a potion!Player now has| " << playerPotion << "potions. \n";
					}

					//upgrade creatures
					creatureHp = 50 + creaturesKilled * 2;				//creature stats increases if another creature dies by +2
					creatureDmg = 5 + creaturesKilled * 2;
					creatureArmor = 5 + creaturesKilled * 2;
					creatureLuck = 0 + creaturesKilled * 2;

					//give player some point to increase his power
					char symbol;
					for (int i = 0; i < 5; i++)
					{
						std::cout << "Player's current stats are: "
							<< "Health: " << playerHp
							<< ",Damage: " << playerDmg
							<< ",Armor: " << playerArmor
							<< ",Luck: " << playerLuck;
						std::cout << "\nPlayer now have "<<5-i<< " BSP to spread on attributes, choose wisely! Press H - health , D - damage , A - armor , L - luck \n";
					
						std::cin >> symbol;
							if (!(symbol == 'H' || symbol == 'D' || symbol == 'A' || symbol == 'L'))
							{
								std::cout << "Wrong!Try again. \n";
								i--;
							}
							else
							{
								switch (symbol)
								{
								case 'H': playerHp++; break;
								case 'D': playerDmg++; break;
								case 'A': playerArmor++; break;
								case 'L': playerLuck++; break;
								}
							}
						
					}

					tempPlayerHp = playerHp;				//store new players hp in case he upgraded it for later usage

			}
		}

		//where game ends
		//Player dies
		if (playerHp <= 0)
		{
			std::cout << "Player have died! \n";

			if (freeGames)
			{
				//in case we've killed enough we get free game
				std::cout << "Your killing instinct approved and you have earned a free game! You have "<<freeGames<<"left. Do you want to start a new game? (Y/N) \n";
			}
			else
			{
				//new bitcoin needed
				std::cout << "You have to pay to play more! Do you want to start a new game? (Y/N) \n";
			}

			//get users input and do stuffs
			char isPlay;
			char freeOrPay;
			while (std::cin >> isPlay)
			{
				if (isPlay == 'N')
				{
					playGame = false;
					break;
				}
				else if (isPlay == 'Y')
				{
					if (bitCoins < 20 && freeGames<=0)
					{
						std::cout << "Not enough coins or freegames to play this again! \n";
						return 0;
					}
					else
					{
						std::cout << "Press F - freegame, P - pay by bitCoins \n";
						while (std::cin >> freeOrPay)
						{
							if (freeOrPay=='F')
								break;
							else if (freeOrPay == 'P')
								break;
							else
								std::cout << "Wrong button!Try again. \n";
							
						}
					}
					
					if (freeOrPay == 'F')
					{
						freeGames--;
						break;
					}
					else if(freeOrPay == 'P')
					{
						bitCoins -= 20;				//each game cost 20 bitCoins
						break;
					}
				}
				else
				{
					std::cout << "Wrong button!Try again. \n";
				}
			}
		}

	} while (playGame);

	return 0;
}



int randomNumber(int low, int high)						//using for Creature AI,luckChance, and other chances
{
	srand(time(0));
	return (rand() % (high + 1 - low) + low);
}


int luckChance(int luckStats, int action)						//gives Double DMG or Full Block 
{

	if (((luckStats / 10) * 0.05) * 10 == 0)			//chance = 0
	{
		return 1;
	}
	
	int chance = 10 - (((int)(((luckStats / 10) * 0.05) * 10)) + 1);				//debug formula,doing stuff ,whatever
	
	
	if (action == 1)
	{
		int isDoubleDmg = randomNumber(0, chance);
		if (isDoubleDmg == chance)
		{
			std::cout << "DOUBLE DMG ";
			return 2;
		}
	}
	else if (action == 0)
	{
		int isNoDmg = randomNumber(0, chance);
		if (isNoDmg == chance)
		{
			std::cout << "DMG ABSORBED ";
			return 0;
		}
	}

	return 1;
}


void hpAfterFight(int dmgOfOpponent,int dmgOfUnit, int armorOfUnit,int armorOfOpponent, int& hpOfUnit,int&hpOfOpponent, int luckStatsOfUnit,int luckStatsOfOpponent, int actionUnit, int actionOpponent)			// int& hpOfUnit
{																													// to change value by ref. and not make a copy and return new values
	int dmgReductionByUnit = dmgOfOpponent * (((armorOfUnit / 10) * 5) / 100);
	int dmgReductionByOpponent = dmgOfUnit* (((armorOfOpponent / 10) * 5) / 100);

	int luckBonus = luckChance(luckStatsOfUnit, actionUnit);
	int luckBonusOfOpponent = luckChance(luckStatsOfOpponent, actionOpponent);
	if (actionUnit == 1 && actionOpponent == 1)
	{
		if (luckBonusOfOpponent > 1)
		{
			std::cout << " by Player. ";
		}
		hpOfUnit -= dmgOfOpponent*luckBonusOfOpponent - dmgReductionByUnit;
		
		if ( luckBonus > 1 )
		{
			std::cout << " by Creature. ";
		}
		hpOfOpponent -= dmgOfUnit*luckBonus - dmgReductionByOpponent;
	}
	else if (actionUnit == 0 && actionOpponent == 1)
	{
		if (!(luckBonus))
		{
			std::cout << " by Creature. ";
			hpOfUnit -= luckBonus;
		}
		else
		{
			if (luckBonusOfOpponent > 1)
			{
				std::cout << " by Player. ";
			}
			hpOfUnit -= dmgOfOpponent*luckBonusOfOpponent - (dmgReductionByUnit + (dmgOfOpponent * 50 / 100));
		}
	}
	else if (actionUnit == 1 && actionOpponent == 0)
	{
		if (!(luckBonusOfOpponent))
		{
			std::cout << " by Player. ";
			hpOfOpponent -= luckBonusOfOpponent;
		}
		else
		{
			if (luckBonus > 1)
			{
				std::cout << " by Creature. ";
			}
			hpOfOpponent -= dmgOfUnit*luckBonus - (dmgReductionByOpponent + (dmgOfUnit * 50 / 100));
		}
	}
	
}

































/*
int randomNumber(int low, int high)						//using for Creature AI,luckChance, and other chances
{
	int myNumber;

	std::random_device seed;
	std::mt19937 random(seed());
	std::uniform_int_distribution<int> dist(low, high);

	myNumber = dist(random);
	return myNumber;
}
*/
