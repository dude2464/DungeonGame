//enemy.h

#ifndef __ENEMY_H__
#define __ENEMY_H__
#include "character.h"
#include "treasure.h"

class Enemy: public Character{
public:
	Enemy(int hp, int atk, int def,char race);
	virtual Treasure *dropGold()=0;
	virtual bool withinrad(int x, int y);
	virtual bool hostility();
	virtual ~Enemy();
};

#endif
