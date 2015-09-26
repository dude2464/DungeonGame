//elf.cc
#include "elf.h"
#include "normalhoard.h"
using namespace std;

Elf::Elf() : Enemy(140, 30, 10, 'E') {}
Treasure *Elf::dropGold() {
	Treasure *amt = new NormalHoard();
	return amt;
}
Elf::~Elf() {}
