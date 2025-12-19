#pragma once
#include <iostream>
#include <string>

class Creature
{
public:
	std::string name;
	int hp;
	int max_hp = 100;
	int attack;

	Creature(std::string n, int h, int a);

	virtual void TakeDamage(int damage);
	virtual int AttackFunc();
	bool isDead();
};

