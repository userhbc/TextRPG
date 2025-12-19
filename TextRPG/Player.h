#pragma once
#include <string>
#include <iostream>
#include "Creature.h"
#include "Item.h"
#include <vector>

class Player : public Creature {
public:
	int level = 1;
	int exp = 0;
	int max_exp = 100;
	std::vector<Item*> inventory;
	int maxSlot = 10;
	Player(std::string n);

	void showInfo();

	int AttackFunc() override;

	bool GetItem(Item* item);

	void GetExp(int value);

	void Save();
	void Load();

};