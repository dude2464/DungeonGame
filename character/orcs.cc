//orc.cc
#include "orcs.h"
#include "smallhoard.h"
using namespace std;

Orcs::Orcs() : Enemy(180, 30, 25, 'O') {}

Treasure *Orcs::dropGold() {
	Treasure *amt = new SmallHoard();
	return amt;
}

Orcs::~Orcs() {}
