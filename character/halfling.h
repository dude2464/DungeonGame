//halfling.h
#ifndef __HALFLING_H__
#define __HALFLING_H__
#include "enemy.h"
#include "character.h"

class Halfling: public Enemy {
	
public:
	Halfling();
	Treasure *dropGold();
	~Halfling();
};
#endif