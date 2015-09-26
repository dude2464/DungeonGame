//enemy.cc
#include "enemy.h"
using namespace std;

Enemy::Enemy(int hp, int atk, int def, char race): Character(hp, atk, def, race) {}


bool Enemy::withinrad(int x, int y){
	return true;
}

bool Enemy::hostility(){
	return true;
}

Enemy::~Enemy(){}

