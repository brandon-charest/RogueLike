#include "main.h"
#include "Level.h"
#include "GameManager.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	GameManager gameManager("Level1.txt");

	gameManager.playGame();
	

	return 0;
}

