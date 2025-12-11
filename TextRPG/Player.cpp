#include "Player.h"
#include <cstdlib>

using namespace std;

Player::Player(string n) : name(n) {}

void Player::showInfo() {
    cout << "=== [" << name << "]의 상태 ===" << endl;
    cout << "체력: " << hp << endl;
    cout << "공격력: " << attack << endl;
    cout << "=======================" << endl;
}

void Player::TakeDamage(int damage) {
    hp -= damage;
    if (hp < 0)
        hp = 0;
}

int Player::AttackFunc() {
    if (rand() % 10 < 2)
        return 0;
    else
        return attack;

}
