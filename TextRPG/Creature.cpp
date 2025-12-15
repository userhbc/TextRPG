#include "Creature.h"
#include <cstdlib>

Creature::Creature(std::string n, int h, int a) : name(n), hp(h), attack(a){}

void Creature::TakeDamage(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

int Creature::AttackFunc() {
    return attack;
}

bool Creature::isDead() {
    return hp <= 0;
}