#pragma once
#include <string>
#include <iostream>
#include "Creature.h"

class Item;

class Monster : public Creature
{
public:
	Monster(std::string n, int h, int a);
	int AttackFunc() override;
	Item* DropItem();
};

