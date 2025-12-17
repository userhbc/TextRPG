#pragma once
#include <string>
#include <iostream>
#include "Creature.h"
#include "Item.h"
#include <vector>

class Player : public Creature {
public:
	std::vector<Item*> inventory;
	int maxSlot = 10;
	Player(std::string n);

	void showInfo();

	int AttackFunc() override;

	bool GetItem(Item* item);

};