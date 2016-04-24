#include "Player.h"
#include <random>
#include <iostream>
#include <ctime>
using namespace std;

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
int Player::attack()
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);
}
int Player::takeDamage(int attack)
{	
	attack -= _defense;
		//attack damage is first subtracted from the enemys defense if the attack is above 0 
		//then procede with doing damage.
		if (attack > 0) {
			_health -= attack;
			//checks if player is killed.
			if (_health <= 0) {
				return 1;
			}
		}
		return 0;	
}
void Player::addExperience(int experience)
{
	_experience += experience;
	//level up
	while (_experience > 50) {
		cout << ("YOU LEVELED UP! \n");
		system("PAUSE");
		_experience -= 50;
		_attack += 10;
		_defense += 10;
		_health += 20;
		_level++;

	}
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



