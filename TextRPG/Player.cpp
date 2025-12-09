#include "Player.h"

Player::Player(string n) : name(n) {}

void Player::showInfo() {
    cout << "=== [" << name << "]의 상태 ===" << endl;
    cout << "체력: " << hp << endl;
    cout << "공격력: " << attack << endl;
    cout << "=======================" << endl;
}