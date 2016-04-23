#include "Player.h"


//Constructor, initializes player position to zero
Player::Player()
{
	_x = 0;
	_y = 0;	
}
//Initializes player properties
void Player::init(int level, int health, int attack, int defense, int experience)
{
	_level = level;
	_health = health;
	_attack = attack;
	_defense = defense;
	_experience = experience;
}
//Sets player position
void Player::setPosition(int x, int y)
{
	_x = x;
	_y = y;	
}
//Gets player position using reference variables
void Player::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}



