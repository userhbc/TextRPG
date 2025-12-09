#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player {
public:
	std::string name;
	int hp = 100;
	int attack = 10;

	Player(string n);

	void showInfo();
};