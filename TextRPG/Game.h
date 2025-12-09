#pragma once

#include "Player.h"


class Game
{
public :
	Game();
	~Game();

	void Run();
private :
	Player* player;
	bool isRunning;
	

};

