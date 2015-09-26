//halfling.cc
#include "halfling.h"
#include "normalhoard.h"
using namespace std;

Halfling::Halfling() : Enemy(100, 15, 20, 'L') {}

Treasure *Halfling::dropGold() {
	Treasure *amt = new NormalHoard();
	return amt;
}

Halfling::~Halfling() {}
