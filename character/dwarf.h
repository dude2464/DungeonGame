//dwarf.h
#ifndef __DWARF_H__
#define __DWARF_H__	
#include "enemy.h"
#include "character.h"

class Dwarf: public Enemy {
	
public:
	Dwarf();
	~Dwarf();
	Treasure *dropGold();
};
#endif
