#include "Level.h"
#include "Enemy.h"
#include <fstream> //std::ifstream
#include <iostream>
#include <cstdio>

Level::Level()
{

}

void Level::loadLevel(string fileName, Player &player)
{
	ifstream file;


	file.open(fileName);
	//checks to make sure file opens
	if (file.fail()) {
		perror(fileName.c_str());
		system("PAUSE");
		exit(1);
	}

	string line;
	//loads level
	while (getline(file, line)) {
		_levelData.push_back(line);
	}
	file.close();

	//Process level
	char tile;
	//int i loops through each row
	for (int i = 0; i < _levelData.size(); i++) {
		//int j loops through each character of the row
		for (int j = 0; j < _levelData[i].size(); j++) {
			tile = _levelData[i][j];

			switch (tile) {
			case '@':  //Player
				// j is x position, i is y position
				player.setPosition(j, i);
				break;
			case 'S': //Snake
				//creates enemy
				_enemies.push_back(Enemy("Snake", tile, 3, 1, 10, 50, 1));
				_enemies.back().setPosition(j, i);
				break;
			case 'g': //Goblin
					  //creates enemy
				_enemies.push_back(Enemy("Goblin", tile, 10, 5, 50, 25, 2));
				_enemies.back().setPosition(j, i);
				break;
			case 'O': //Ogre
					  //creates enemy
				_enemies.push_back(Enemy("Ogre", tile, 20, 25, 250, 100, 12));
				_enemies.back().setPosition(j, i);
				break;
			case 'b': //Bandit
					  //creates enemy
				_enemies.push_back(Enemy("Bandit", tile, 15, 3, 100, 50, 5));
				_enemies.back().setPosition(j, i);
				break;
			case 'D': //Dragon
					  //creates enemy
				_enemies.push_back(Enemy("Dragon", tile, 2000, 3000, 5000, 10000, 500));
				_enemies.back().setPosition(j, i);
				break;
			}
		}
	}


}

void Level::printLevel()
{
	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

void Level::movePlayer(char input, Player &player)
{

	int playerX;
	int playerY;

	player.getPosition(playerX, playerY);
	
	switch (input) {
		//move up
	case 'w':
	case 'W':
		//move player up 1 tile
		
		proccessPlayerMove(player, playerX, playerY -1);
		break;
		//move left

	case 'a':
	case 'A':
		proccessPlayerMove(player, playerX -1, playerY);
		break;

		//move down
	case 's':
	case 'S':
		proccessPlayerMove(player, playerX, playerY + 1);
		break;
		
		//move right
	case 'd':
	case 'D':
		proccessPlayerMove(player, playerX + 1, playerY);
		break;

	default:
		cout << ("Invalid input!\n");
		system("PAUSE");
	}
}

//checks tiles surrounding player
char Level::getTile(int x, int y)
{
	return _levelData[y][x];
}

void Level::setTile(int x, int y, char tile)
{
	/*         Swaps tiles as player moves through them
	#####	   #####
	#@..# ---> #.@.#      this is an example for when 
	#...#	   #...#      player moves right one tile
	#####      #####                                         */
	_levelData[y][x] = tile;
}

void Level::proccessPlayerMove(Player & player, int targetX, int targetY)
{
	int playerX;
	int playerY;
	player.getPosition(playerX, playerY);

	char moveTile = getTile(targetX, targetY);

	switch (moveTile) {	
	case '.':
		player.setPosition(targetX, targetY);
		setTile(playerX, playerY, '.');
		setTile(targetX, targetY, '@');
		break;
	case '#':
		break;
	default:
		battleMonster(player, targetX, targetY);
		break;
	}
}

void Level::battleMonster(Player & player, int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int playerX;
	int playerY;
	int playerHealth;
	int attackRoll;
	int attackResult;
	string enemyName;

	player.getPosition(playerX, playerY);

	for (int i = 0; i < _enemies.size(); i++) {

		_enemies[i].getPosition(enemyX, enemyY);
		enemyName = _enemies[i].getName();
			if (targetX == enemyX && targetY == enemyY) {
				//Battle Takes Place

				attackRoll = player.attack();
				printf("\nPlayer attacked a %s for %d damage!\n", enemyName.c_str(), attackRoll);
				attackResult = _enemies[i].takeDamage(attackRoll);

				if (attackResult != 0) {
					setTile(targetX, targetY, '.');
					printLevel();
					printf("You have slain %s!\n", enemyName.c_str());
					system("PAUSE");
					player.addExperience(attackResult);
					
					return;
				}

				//Enemy turn
				attackRoll = _enemies[i].attack();
				printf("\n%s attacked Player for %d damage!\n", enemyName.c_str(), attackRoll);
				attackResult = player.takeDamage(attackRoll);
				playerHealth = player.getCurrentHealth();
				printf("***Players Current Health: %d\n", playerHealth);
				if (attackResult != 0) {
					setTile(playerX, playerY, 'X');
					printLevel();
					printf("You have been slain by %s!\n", enemyName.c_str());
					printf("***Players Current Health: %d\n", playerHealth);
					system("PAUSE");	

					exit(0);
				}
				system("PAUSE");
				return;
		}
	}
}

