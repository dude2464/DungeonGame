#include "item.h"
using namespace std;

Item::Item(char type) : Object(type) {}

bool Item::attackability() {
	return false;
}

Item::~Item() {}
