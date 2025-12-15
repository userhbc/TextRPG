#include "Monster.h"
#include <cstdlib>
using namespace std;


Monster::Monster(string n, int h, int a) :Creature(n,h,a) {}

int Monster::AttackFunc() {
	if (rand() % 10 < 2)
		return 0;
	else
		return attack;

}