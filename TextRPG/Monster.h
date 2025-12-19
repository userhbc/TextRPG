#pragma once
#include <string>
#include <iostream>
#include "Creature.h"

class Item;

class Monster : public Creature
{
public:
	int exp_reward;

	Monster(std::string n, int h, int a, int e);
	int AttackFunc() override;
	Item* DropItem();
};

