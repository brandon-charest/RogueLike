#pragma once
#include <vector>
#include <string>

using namespace std;

class Level
{
public:
	Level();
	void loadLevel(string fileName);
	void printLevel();
private:
	vector<string> _levelData;
};

