#include "Enemy.h"
#include <ctime>
#include <random>


Enemy::Enemy(string name, char tile, int attack, int defense, int health, int xp, int level)
{
	_name = name;
	_tile = tile;
	_level = level;
	_attack = attack;
	_defense = defense;
	_health = health;
	_experienceValue = xp;
}

int Enemy::attack()
{	
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> attackRoll(0, _attack);

	return attackRoll(randomEngine);	
}

int Enemy::takeDamage(int attack)
{
	attack -= _defense;
	//attack damage is first subtracted from the enemys defense if the attack is above 0 
	//then procede with doing damage.
	if (attack > 0) {
		_health -= attack;
		//checks if enemy is killed and returns XP.
		if (_health <= 0) {
			return _experienceValue;
		}
	}	
	return 0;
	
}

//Sets enemy position
void Enemy::setPosition(int x, int y)
{
	_x = x;
	_y = y;
}
//Gets enemy position using reference variables
void Enemy::getPosition(int &x, int &y)
{
	x = _x;
	y = _y;
}

char Enemy::getMove(int playerX, int playerY)
{
	static default_random_engine randomEngine(time(NULL));
	uniform_int_distribution<int> moveRoll(0, 8);

	int distance;
	int dX = _x - playerX;
	int dY = _y - playerY;
	int absDX = abs(dX);
	int absDY = abs(dY);
	distance = absDX + absDY;

	if (distance <= 5) {
		//move along X axis
		if (absDX > absDY) {
			if (dX > 0) {return 'a';}
			else { return 'd'; }
		}
		else { //move along Y axis
			if (dY > 0) { return 'w'; }
			else { return 's'; }
		}
	}

	int randomMove = moveRoll(randomEngine);
	switch (randomMove) {
	case 0:
		return 'a';
	case 1:
		return 'w';
	case 2: 
		return 's';
	case 3:
		return 'd';
	default:
		return '.';

	}

}
