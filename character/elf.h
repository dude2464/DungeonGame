//elf.h
#ifndef __ELF_H__
#define __ELF_H__	
#include "enemy.h"
#include "character.h"

class Elf: public Enemy {
	
public:
	Elf();
	Treasure *dropGold();
	~Elf();
};
#endif