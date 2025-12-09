#pragma once

#include "Player.h"

using namespace std;

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

