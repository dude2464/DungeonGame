//enemyfactory.cc
#include "enemyfactory.h"

#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
using namespace std;
class DragonHoard;

Enemy *EnemyFactory::generateEnemy(char c, Treasure *treasure) {
	Enemy *en;
	if(c == 'H') {
		en = new Human();
	}
	else if(c == 'W') {
		en = new Dwarf();
	}
	else if(c == 'E') {
		en = new Elf();
	}
	else if(c == 'O') {
		en = new Orcs();
	}
	else if(c == 'M') {
		en = new Merchant();
	}
	else if(c == 'D') {
		en = new Dragon(dynamic_cast<DragonHoard*>(treasure));
	}
	else if(c == 'L') {
		en = new Halfling();	
	}
	else {
		en = 0;
	}

	return en;
}
