#include "Player.h"
#include <cstdlib>

using namespace std;

Player::Player(string n) : Creature(n,100,10){}

void Player::showInfo() {
    cout << "=== [" << name << "]ÀÇ »óÅÂ ===" << endl;
    cout << "Ã¼·Â: " << hp << endl;
    cout << "°ø°Ý·Â: " << attack << endl;
    cout << "=======================" << endl;
    cout << "--- [°¡¹æ (" << inventory.size() << "/" << maxSlot << ")] ---" << endl;
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
    cout << "¾ÆÀÌÅÛ ¹ß°ß È¹µæÇÒ±î?\nY/N" << '\n';
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        if (inventory.size() < maxSlot) {
            inventory.push_back(item);
            cout << item->name << " È¹µæ!" << '\n';
            return true;
        }
        else {
            cout << "°¡¹æÀÌ ²Ë Ã¡´Ù! ¾ÆÀÌÅÛ È¹µæ ½ÇÆÐ" << '\n';
            delete item;
            return false;
        }
    }
    else {
        cout << "¾ÆÀÌÅÛÀ» ¹ö·È´Ù" << '\n';
        delete item;
        return false;
    }

}