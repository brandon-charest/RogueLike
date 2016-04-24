#include "GameManager.h"
#include<iostream>
#include<conio.h>
//Constructor sets up game
GameManager::GameManager(string levelFile)
{

	_player.init(1, 100, 10, 5, 0);
	_level.loadLevel(levelFile, _player);
	_level.printLevel();
	system("PAUSE");
}

void GameManager::playGame()
{
	bool isDone = false;
	while (!isDone == true) {
		_level.printLevel();
		playerMove();
		_level.updateEnemy(_player);
	}
}

void GameManager::playerMove()
{
	char input;
	cout << "Enter a move command(w/a/s/d): ";
	input = _getch();
	_level.movePlayer(input, _player);

}


