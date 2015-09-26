//playerfactory.cc
#include "playerfactory.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
using namespace std;

Player *PlayerFactory::createPlayer(char c) {
	Player *pl;
	if(c == 'S') {
		pl = new Shade();
	}
	else if(c == 'R') {
		pl = new Drow();
	}
	else if(c == 'V') {
		pl = new Vampire();
	}
	else if(c == 'T') {
		pl = new Troll();
	}
	else if(c == 'G') {
		pl = new Goblin();
	}
	else {
		pl = 0;
	}

	return pl;
}