#include "Monster.h"
#include <cstdlib>
#include "Item.h"
using namespace std;


Monster::Monster(string n, int h, int a, int e) :Creature(n,h,a), exp_reward(e) {}

int Monster::AttackFunc() {
	if (rand() % 10 < 2)
		return 0;
	else
		return attack;

}

Item* Monster::DropItem() {
	return new Item(name + "ÀÇ Ã¼¾×", 5);
}