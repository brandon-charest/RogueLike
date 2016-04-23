#include "Level.h"
#include <fstream> //std::ifstream
#include <iostream>
#include <cstdio>

Level::Level()
{

}

void Level::loadLevel(string fileName)
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
}

void Level::printLevel()
{
	cout << string(100, '\n');

	for (int i = 0; i < _levelData.size(); i++) {
		printf("%s\n", _levelData[i].c_str());
	}
	printf("\n");
}

