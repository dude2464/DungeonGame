//dragon.h

#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemy.h"
#include "dragonhoard.h"

class Dragon:public Enemy{
	DragonHoard *treasure;
public:
	Dragon(DragonHoard *treasure);
	bool withinrad(int x, int y);
	Treasure *dropGold();
	~Dragon();
};

#endif
