#include "Player.h"
#include <cstdlib>

using namespace std;

Player::Player(string n) : Creature(n,100,10){}

void Player::showInfo() {
    cout << "=== [" << name << "]의 상태 ===" << endl;
    cout << "체력: " << hp << endl;
    cout << "공격력: " << attack << endl;
    cout << "=======================" << endl;
    cout << "--- [가방 (" << inventory.size() << "/" << maxSlot << ")] ---" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        cout << i + 1 << ". " << inventory[i]->name << '\n';
    }
    cout << "=======================" << '\n';
}


int Player::AttackFunc() {
    if (rand() % 10 < 2)
        return 0;
    else
        return attack;

}

bool Player::GetItem(Item* item) {
    string answer;
    cout << "아이템 발견 획들할까?\nY/N" << '\n';
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        if (inventory.size() < maxSlot) {
            inventory.push_back(item);
            return true;
        }
        else {
            cout << "가방이 꽉 찼다! 아이템 획득 실패" << '\n';
            delete item;
            return false;
        }
    }
    else {
        cout << "아이템을 버렸다" << '\n';
        delete item;
        return false;
    }

}