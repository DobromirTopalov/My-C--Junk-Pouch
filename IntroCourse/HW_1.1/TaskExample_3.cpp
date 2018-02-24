#include <iostream>
#include <random>

int randomNumber(int low = 0, int high = 1);
int luckChance(int luckStats, int action);
void hpAfterFight(int dmgOfOpponent, int armorOfUnit, int& hpOfUnit, int luckStatsOfUnit, int actionUnit);


int main()
{
	bool playGame = true;									//game runs untill player press Exit or N(if dead)
	
	do														//be sure to run once at least
	{
		std::cout << "There is a monster in front of you. You have these commands available: \n";
		std::cout << "I - show stats | A - attack monster | D - defense | P - drink potion | X - exit game \n";

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

		int creatureHp = 25;					//creature stats
		int creatureDmg = 5;
		int creatureArmor = 5;
		int creatureLuck = 0;

		while (playerHp > 0 )					//kill and chill while you have hp
		{

			if (creatureHp > 0)
			{
				std::cout << "Make action!\n";
				std::cin >> playerAction;						//getting player action
				if ( !(playerAction == 'A' || playerAction == 'D' || playerAction == 'I' || playerAction == 'P' || playerAction == 'X') )
				{
					std::cout << "Invalid command!Choose again: \n";
					continue;
				}
				

				switch (playerAction)							//check what action player has chosen
				{
					int creatureAction;

					// show muscles
					case 'I': std::cout << "Your stats are: "
						<< "Health: " << playerHp
						<< ",Damage: " << playerDmg
						<< ",Armor: " << playerArmor
						<< ",Luck: " << playerLuck
						<< ",Potions: " << playerPotion << "\n"; break;

					case 'A':			//Attack									//block of code in switch case
					{
						std::cout << "Player did an attack! and ";

						creatureAction = randomNumber();							//Creature AI
						if (creatureAction)
						{
							std::cout << "Creature did an attack! \n";
							hpAfterFight(creatureDmg, playerArmor, playerHp, playerLuck, 1);			//playerHpAfter
							hpAfterFight(playerDmg, creatureArmor, creatureHp, creatureLuck, 1);		//creatureHpAfter	
						}
						else
						{
							std::cout << "Creature did defense itself! \n";
							hpAfterFight(playerDmg, creatureArmor, creatureHp, creatureLuck, 0);			//playerHpAfter
						}

						std::cout << "Player has: " << playerHp << " hp and Creature has: " << creatureHp << " hp\n";
					}
					break;


					case 'D':		//Defense
					{
						std::cout << "Player did defense himself and ";

						creatureAction = randomNumber();
						if (creatureAction)
						{
							std::cout << "Creature did an attack! \n";
							hpAfterFight(creatureDmg, playerArmor, playerHp, playerLuck, 0);			//playerHpAfter	
						}
						else
						{
							std::cout << "Creature did defense itself! \n";
						}

						std::cout << "Player has: " << playerHp << " hp and Creature has: " << creatureHp << " hp\n";
					}
					break;

					case 'P':		//Potions
					{
						if (playerPotion > 0)									//if player still has potions left
						{
							std::cout << "Player used a potion and ";
							playerHp = tempPlayerHp;							//tempPlayerHp stores player total HP before each fight
							playerPotion--;
						}
						else
						{
							std::cout << "Player could not use a potion and ";
						}

						creatureAction = randomNumber();
						if (creatureAction)
						{
							std::cout << "Creature did an attack! \n";
							hpAfterFight(creatureDmg, playerArmor, playerHp, playerLuck, 1);				//playerHpAfter
						}
						else
						{
							std::cout << "Creature did defense itself! \n";
						}

						std::cout << "Player has: " << playerHp << " hp and Creature has: " << creatureHp << " hp\n";
					}
					break;

					case 'X': std::cout << "You have exited the game! \n"; return 0; break;
				}
			}
			else				// if creature got killed
			{
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
					}

					//upgrade creatures
					creatureHp = 25 + creaturesKilled * 2;				//creature stats increases if another creature dies by +2
					creatureDmg = 5 + creaturesKilled * 2;
					creatureArmor = 5 + creaturesKilled * 2;
					creatureLuck = 0 + creaturesKilled * 2;

					//give player some point to increase his power
					char symbol;
					for (int i = 0; i < 5; i++)
					{
						std::cout << "You have "<<5-i<< " stats points to spread between your attributes,choose wisely! Press H - health , D - damage , A - armor , L - luck \n";
						std::cin >> symbol;
						switch (symbol)
						{
							case 'H': playerHp++; break;
							case 'D': playerDmg++; break;
							case 'A': playerArmor++; break;
							case 'L': playerLuck++; break;
						}
					}

					tempPlayerHp = playerHp;				//store new players hp in case he upgraded it for later usage

			}
		}

		//where game ends
		//Player dies
		if (playerHp <= 0)
		{
			std::cout << "You've died! ";

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
						std::cout << "Not enough coins to play this!\n";
						return 0;
					}
					else if (freeGames)
					{
						break;
					}
					else
					{
						bitCoins -= 20;				//each game cost 20 bitCoins
						break;
					}
				}
				else
				{
					std::cout << "Wrong button!Try again later. \n";
				}
			}
		}

	} while (playGame);

	return 0;
}



int randomNumber(int low, int high)						//using for Creature AI,luckChance, and other chances
{
	int myNumber;

	std::random_device seed;
	std::mt19937 random(seed());
	std::uniform_int_distribution<int> dist(low, high);

	myNumber = dist(random);
	return myNumber;
}

int luckChance(int luckStats, int action)						//gives Double DMG or Full Block 
{

	if (((luckStats % 10) * 5 / 100) == 0)			//division by 0
	{
		return 1;
	}

	int chance = 1 / ((luckStats % 10) * 5 / 100);
	if (action == 1)
	{
		int isDoubleDmg = randomNumber(0, chance - 1);
		if (isDoubleDmg == chance - 1)
		{
			return 2;
		}
	}
	else if (action == 0)
	{
		int isNoDmg = randomNumber(0, chance - 1);
		if (isNoDmg == chance - 1)
		{
			return 0;
		}
	}

	return 1;
}


void hpAfterFight(int dmgOfOpponent, int armorOfUnit, int& hpOfUnit, int luckStatsOfUnit, int actionUnit)			// int& hpOfUnit
{																													// to change value by ref. and not make a copy and return new values
	int dmgReductionByUnit = dmgOfOpponent * (((armorOfUnit % 10) * 5) / 100);
	int luckBonus = luckChance(luckStatsOfUnit, actionUnit);
	if (actionUnit == 1)
	{
		hpOfUnit -= dmgOfOpponent*luckBonus - (dmgReductionByUnit);
	}
	else if (actionUnit == 0)
	{
		if (!(luckBonus))
		{
			hpOfUnit -= luckBonus;
		}
		else
		{
			hpOfUnit -= dmgOfOpponent - (dmgReductionByUnit + (dmgOfOpponent * 50 / 100));
		}
	}
}
