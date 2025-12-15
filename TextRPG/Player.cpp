#include "Player.h"
#include <cstdlib>

using namespace std;

Player::Player(string n) : Creature(n,100,10){}

void Player::showInfo() {
    cout << "=== [" << name << "]의 상태 ===" << endl;
    cout << "체력: " << hp << endl;
    cout << "공격력: " << attack << endl;
    cout << "=======================" << endl;
}


int Player::AttackFunc() {
    if (rand() % 10 < 2)
        return 0;
    else
        return attack;

}
