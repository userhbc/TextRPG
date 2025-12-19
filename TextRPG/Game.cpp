#include <iostream>
#include <ctime>
#include "Game.h"
#include "Monster.h"

using namespace std;

Game::Game() {
	srand(time(NULL));
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
		cout << "\n1.정보보기	2.사냥터 입장	3. 저장	4.불러오기	5.종료"	<< '\n';
		cin >> input;

		if (input == 1)
			player->showInfo();
		else if (input == 2)
			Game::Battle();
		else if (input == 3)
			player->Save();
		else if (input == 4)
			player->Load();
		else if (input == 5) {
			cout << "게임 종료";
			isRunning = false;
		}
	}
}

void Game::Battle() {
	Monster monster("slime", 35, 10,10);
	cout << "몬스터 출현!" << '\n';
	while (true) {
		int input;

		cout << player->name << " HP: " << player->hp << '\n'
			<< monster.name << " HP: " << monster.hp << '\n';

		cout << "\n1.공격		2.도망" << '\n';
		cin >> input;
		if (input == 1) {
			int damage = player->AttackFunc();
			if (damage > 0) {
				cout << "공격 적중! " << damage << "의 데미지를 입혔습니다.\n";
				monster.TakeDamage(damage);

				if (monster.isDead()) {
					cout << "승리!" << endl;
					Item* newItem = monster.DropItem();
					player->GetExp(monster.exp_reward);
					player->GetItem(newItem);
					break;
				}
			}
			else
				cout << "공격이 빗나감!\n";

			cout << "몬스터의 반격!\n";
			int monsterDamage = monster.AttackFunc();
			if (monsterDamage > 0) {
				cout << monsterDamage << "의 피해를 입음.\n";
				player->TakeDamage(monsterDamage);

				if (player->hp <= 0) {
					cout << "패배했습니다..." << endl;
					isRunning = false;
					break;
				}
			}
			else
				cout << "몬스터의 공격이 빗나갔다!\n";
		}
		else if (input == 2) {
			break;
		}
	}
}

