//orc.h
#ifndef __ORCS_H__
#define __ORCS_H__
#include "enemy.h"
#include "character.h"

class Orcs: public Enemy {
	
public:
	Orcs();
	Treasure *dropGold();
	~Orcs();
};
#endif
