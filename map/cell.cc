#include <iostream>
#include "cell.h"
using namespace std;

Cell::Cell():type(' '),radnum(0) {
	for(int i=0; i<8; i++) {
		radius[i] = 0;
	}
	p=0;
}

Cell::~Cell(){
	for(int i=0; i < 8; i++) {
		radius[i] = 0;
	}
	p=0;
}

void Cell::collectRad(Cell *c) {
	radius[radnum]=c;	
	radnum++;
}

void Cell::setType(char c) {
	type = c;
}

Object *Cell::getP() {
	return p;
}


void Cell::setP(Object *p) {
	this->p = p;
}

Object *Cell::releaseP() {
	Object *ret = p;
	p = 0;
	return ret;
}

bool Cell::hasPlayer() {
	return 	(p && p->isPlayer());
}

Object *Cell::findPlay() {
	Object *ret = 0;
	for(int i=0; i<8; i++) {
		if(radius[i] && radius[i]->hasPlayer()) {
			ret = radius[i]->getP();
		}
	}
	return ret;
}

void Cell::printC() {
	if(p != 0) {
		p->ps();
	}
	else {
		cout << type;	
	}
	
}

int Cell::canMove() {
	return 	(p != 0 && p->selectability())? 4 :
			(p != 0)? 0 :
			(type == '.')? 1 :
			(type == '+' || type == '#')? 2 :
			(type == '/')? 3 : 0;
}
