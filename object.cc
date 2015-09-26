#include <iostream>
#include "object.h"

using namespace std;

Object::Object(char c):	
	s(c),
	x(0),
	y(0){}

void Object::movePiece(int x, int y){
	this->x=x;
	this->y=y;
}

int Object::retX(){
	return x;
}

int Object::retY(){
	return y;
}

void Object::ps(){
	cout<<s;
}

bool Object::isPlayer(){
	return false;
}
