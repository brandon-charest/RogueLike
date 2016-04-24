#pragma once
#include "Player.h"
#include "Level.h"

#include <string>

using namespace std;

class GameManager
{
public:
	GameManager(string levelFile);
	
	void playGame();
	void playerMove();
private:
	Level _level;
	Player _player;	
};

