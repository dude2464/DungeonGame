//merchant.cc
#include "merchant.h"
#include "merchanthoard.h"
using namespace std;

bool Merchant::hostile = false;

Merchant::Merchant() : Enemy(30, 70, 5,'M') {
}

void Merchant::defend(int targetAtk) {
	hostile = true;
	Character::defend(targetAtk);
}

Treasure *Merchant::dropGold() {
	Treasure *amt = new MerchantHoard();
	return amt;
}

bool Merchant::hostility() {
	return hostile;
}

Merchant::~Merchant() {}
