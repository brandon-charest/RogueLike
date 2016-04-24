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
	

	//Getters
	char getTile(int x, int y);

	//Setters
	void setTile(int x, int y, char tile);

private:
	void proccessPlayerMove(Player &player, int targetX, int targetY);
	void battleMonster(Player &player, int targetX, int targetY);
	vector <Enemy> _enemies;
	vector<string> _levelData;
};

