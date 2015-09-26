//human.h
#ifndef __HUMAN_H__
#define __HUMAN_H__
#include "enemy.h"
#include "character.h"
#include "normalhoard.h"

class Human: public Enemy{
public:
	Human();
	Treasure *dropGold();
	~Human();
};

#endif
