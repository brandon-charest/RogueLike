#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

using namespace std;

class Level
{
public:
	Level();
	void loadLevel(string fileName, Player &player);
	void printLevel();
	void movePlayer(char input, Player &player);
	void updateEnemy(Player &player);

	//Getters
	char getTile(int x, int y);

	//Setters
	void setTile(int x, int y, char tile);
	void setNumPrints(int numPrints) { _numPrints = _numPrints; }
private:
	//numPrints used for padding on bottom of screen
	int _numPrints;

	void proccessPlayerMove(Player &player, int targetX, int targetY);
	void processEnemyMove(Player &player, int enemyIndex, int targetX, int targetY);
	void battleEnemy(Player &player, int targetX, int targetY);
	vector <Enemy> _enemies;
	vector<string> _levelData;
};

