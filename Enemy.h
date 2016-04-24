#pragma once
#include <string>

using namespace std;

class Enemy
{
public:
	//constructor
	Enemy(string name, char tile, int attack, int defense, int health, int xp, int level);
	int attack();
	int takeDamage(int attack);
	//Setters
	void setPosition(int x, int y);
	//Getters
	void getPosition(int &x, int &y);
	string getName() { return _name; }

private:
	string _name;
	char _tile;

	int _attack;
	int _defense;
	int _health;
	int _experienceValue;
	int _level;

	//Position
	int _x;
	int _y;

	//future content to have enemys drop weapons or other items
	//have a %rate for the drops
	//vector<Items> possibleDrops;
};

