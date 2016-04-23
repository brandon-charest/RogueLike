#pragma once
class Player
{
public:
	Player();
	void init(int level, int health, int attack, int defense, int experience);

	//Setters
	void setPosition(int x, int y);

	//Getters
	void getPosition(int &x, int &y);

private:
	//Properties
	int _level;
	int _health;
	int _attack;
	int _defense;
	int _experience;

	//Position
	int _x;
	int _y;
};

