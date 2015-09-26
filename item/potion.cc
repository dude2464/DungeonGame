#include<string>
#include "item.h"
#include "potion.h"

using namespace std;

Potion::Potion(string type, int value):
	Item('P'), type(type), value(value){}

bool Potion::usability() {
	return true;
}

bool Potion::selectability() {
	return false;
}

string Potion::getType() {
	return type;
}

int Potion::getEffect() {
	return value;
}

Potion::~Potion(){}
