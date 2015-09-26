//human.cc
#include "human.h"
using namespace std;

Human::Human() : Enemy(140, 20, 20, 'H') {}

Treasure *Human::dropGold() {
	Treasure *amt = new NormalHoard();
	return amt;
}

Human::~Human() {}
