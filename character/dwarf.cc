//dwarf.cc
#include "dwarf.h"
#include "smallhoard.h"
#include <iostream>
using namespace std;

Dwarf::Dwarf() : Enemy(100, 20, 30, 'W') {}

Treasure *Dwarf::dropGold() {
	Treasure *amt = new SmallHoard();
	return amt;
}

Dwarf::~Dwarf() {}
