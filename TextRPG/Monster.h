#pragma once
#include <string>
#include <iostream>
class Monster
{
public:
	std::string name;
	int hp;
	int attack;
	int max_hp = 100;

	Monster(std::string n, int h, int a);
	void showInfo();
	void TakeDamage(int damage);
	bool isDead();
};

