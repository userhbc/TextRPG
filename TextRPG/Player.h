#pragma once
#include <string>
#include <iostream>
#include "Creature.h"

class Player : public Creature {
public:

	Player(std::string n);

	void showInfo();

	int AttackFunc() override;
};