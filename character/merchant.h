//merchant.h
#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include "enemy.h"
#include "character.h"

class Merchant: public Enemy {
	static bool hostile;
public:
	Merchant();
	void defend(int targetAtk);
	Treasure *dropGold();
	bool hostility();
	~Merchant();
};

#endif
