//treasure.cc

#include "treasure.h"
using namespace std;

Treasure::Treasure(int amt): Item('G'),amt(amt){
}

bool Treasure::selectability(){
	return true;
}

bool Treasure::usability(){
	return false;
}

int Treasure::getAmt(){
	return amt;
}

Treasure::~Treasure(){}
