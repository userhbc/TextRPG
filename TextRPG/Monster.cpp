#include "Monster.h"
#include <cstdlib>
using namespace std;


Monster::Monster(string n, int h, int a) : name(n), hp(h), attack(a) {}

void Monster::showInfo() {
	cout << name << '\n' << hp;
}

void Monster::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0)
		hp = 0;
}

bool Monster::isDead() {
	if (hp <= 0) {
		cout << "몬스터 처치" << '\n';
		return true;
	}
	else
		return false;
}

int Monster::AttackFunc() {
	if (rand() % 10 < 2)
		return 0;
	else
		return attack;

}