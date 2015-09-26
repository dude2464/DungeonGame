//enemyfactory.h

#ifndef __ENEMYFACTORY__H
#define __ENEMYFACTORY__H
#include "enemy.h"

class Treasure;

class EnemyFactory {
public:
	Enemy *generateEnemy(char c, Treasure *treasure = 0);
};

#endif
