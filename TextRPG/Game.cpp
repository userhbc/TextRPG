#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() {
	isRunning = true;

	string name;
	cout << "Player name : ";
	cin >> name;
	player = new Player(name);
}

Game::~Game() {
	if (player != nullptr)
		delete player;
}

void Game::Run() {
	while (isRunning) {
		int input;
		cout << "\n1.정보보기	2.종료" << '\n';
		cin >> input;

		if (input == 1)
			player->showInfo();
		if (input == 2)
			cout << "게임 종료";
			isRunning = false;
	}
}

