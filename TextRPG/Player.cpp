#include "Player.h"
#include <cstdlib>
#include <fstream>

using namespace std;

Player::Player(string n) : Creature(n,100,10){}

void Player::showInfo() {
    cout << "=== [" << name << "]의 상태 ===" << endl;
    cout << "Lv." << level << endl;
    cout << "경험치: " << exp << " / " << max_exp << endl;
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
    cout << "아이템 발견 획득할까?\nY/N" << '\n';
    cin >> answer;
    if (answer == "Y" || answer == "y") {
        if (inventory.size() < maxSlot) {
            inventory.push_back(item);
            cout << item->name << " 획득!" << '\n';
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

void Player::GetExp(int value) {
    exp += value;
    cout << value << " 경험치를 획득했습니다." << '\n';
    while (exp >= max_exp) {
        level++;
        exp -= max_exp;

        max_exp = (int)(max_exp * 1.2);
        max_hp += 20;
        hp = max_hp;
        attack += 3;
        
        cout << "🎉 레벨 업! (Lv." << level << ") - 능력치가 상승했습니다!" << '\n';

    }
}

void Player::Save() {
    ofstream file("save.txt");

    if (file.is_open()) {
        file << name << '\n';
        file << level << '\n';
        file << hp << '\n';
        file << max_hp << '\n';
        file << attack << '\n';
        file << exp << '\n';
        file << max_exp << '\n';

        file << inventory.size() << '\n';
        for (Item* item : inventory) {
            file << item->name << '\n';
            file << item->score << '\n';
        }

        file.close();
        cout << "저장에 성공하였습니다!" << '\n';
    }
    else
        cout << "오류 : 저장에 실패하였습니다." << '\n';

}

void Player::Load() {
    std::ifstream file("save.txt");

    if (file.is_open()) {
        for (Item* item : inventory) { delete item; }
        inventory.clear();

        file >> name;
        file >> level;
        file >> hp;
        file >> max_hp;
        file >> attack;
        file >> exp;
        file >> max_exp;

        int itemCount;
        file >> itemCount;

        for (int i = 0; i < itemCount; i++) {
            std::string itemName;
            int itemScore;

            file >> itemName;
            file >> itemScore;

            inventory.push_back(new Item(itemName, itemScore));
        }

        file.close();
        std::cout << "저장된 데이터를 불러왔습니다!" << std::endl;
    }
    else {
        std::cout << "오류: 저장된 파일이 없습니다." << std::endl;
    }
}