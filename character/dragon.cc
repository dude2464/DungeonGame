//dragon.cc
#include "dragon.h"

Dragon::Dragon(DragonHoard *treasure): Enemy(150, 20, 20 ,'D'), treasure(treasure){}

bool Dragon::withinrad(int x, int y){
	return treasure->withinrad(x, y);
}

Treasure *Dragon::dropGold(){
	return 0;
}

Dragon::~Dragon(){
	treasure->lockOff();
}
