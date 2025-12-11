#pragma once

#include "Player.h"
#include "Monster.h"

class Game
{
public :
	Game();
	~Game();

	void Run();
	void Battle();

private :
	Player* player;
	bool isRunning;
	

};

