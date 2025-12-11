#include <iostream>
#include "Game.h"
#include "Monster.h"

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
		cout << "\n1.정보보기	2.사냥터 입장	3. 종료"	<< '\n';
		cin >> input;

		if (input == 1)
			player->showInfo();
		else if (input == 2)
			Game::Battle();
		else if (input == 3) {
			cout << "게임 종료";
			isRunning = false;
		}
	}
}

void Game::Battle() {
	Monster slime("slime", 35, 10);
	cout << "몬스터 출현!" << '\n';
	while (true) {
		int input;

		cout << player->name << " HP: " << player->hp << '\n'
			<< slime.name << " HP: " << slime.hp << '\n';

		cout << "1.공격		2.도망" << '\n';
		cin >> input;
		if (input == 1) {
			slime.TakeDamage(player->attack);
			player->TakeDamage(slime.attack);
			if (slime.isDead()) {
				cout << "승리!";
				break;
			}
			else if (player->hp <= 0) {
				cout << "플레이어 패배 \n 게임 종료";
				isRunning = false;
				break;
			}
		}
		else if (input == 2) {
			break;
		}
	}
}

