//character.cc
#include "character.h"
#include <cmath>
#include <iostream>
#include <string>
#include <climits>
using namespace std;

Character::Character(int hp, int atk, int def, char race): Object(race),
					hp(hp), atk(atk), def(def), cur_hp(hp),  effect_atk(0), effect_def(0){}

int Character::cur_atk() {
	if((atk + effect_atk) < 0){
		return 0;
	}
	else{
		return atk + effect_atk;
	}
}

int Character::cur_def() {
	if((def + effect_def) < 0){
		return 0;
	}
	else{
		return def + effect_def;
	}
}

void Character::diminishEffect() {
	effect_atk = 0;
	effect_def = 0;
}

void Character::attack(Character &op) {
	if(race == 'E' && op.race != 'R'){
		op.defend(cur_atk() * 2);
	}
	if(race == 'O' && op.race == 'G'){
		op.defend(cur_atk() * 1.5);	
	}
	else{
		op.defend(cur_atk());
	}
	if(race == 'V'){
		hp = INT_MAX;
		if(op.race != 'W'){
		cur_hp += 5;
		}
	if (race == 'T'){
		hp = 120;
			if(op.race == 'W'){
				cur_hp -= 5;
			}
			else{
				cur_hp += 5;
			}
		}
	}
}

void Character::defend(int op_atk) {
	int dmg = (int)ceil( (100/(double)(100+def)) * op_atk);
	hp -= dmg;
}

void Character::use(Potion &potion) {
	string potion_type = potion.getType();
	if(potion_type == "RH" || potion_type == "PH") {
		if(race == 'R'){
			hp += 1.5 * (potion.getEffect());
		}
		else{
			hp += potion.getEffect();
		}
		if(hp < cur_hp) {
			cur_hp = hp;
		}
	} 
	else if(potion_type == "BA" || potion_type == "WA") {
		if(race == 'R'){
			effect_atk += potion.getEffect();
		}
		else{
			effect_atk += potion.getEffect();
		}
		if(cur_atk() < 0) {
			effect_atk = -atk;
		}
	} 
	else if(potion_type == "BD" || potion_type == "WD") {
		if(race == 'R'){
			effect_def += potion.getEffect();
		}
		else{
			effect_def += potion.getEffect();
		}
		if(cur_def() < 0) {
			effect_def = -def;
		}
	}
}

void Character::movePiece(int x, int y) {
	this->x = x;
	this->y = y;
}


bool Character::slain() {
	return (hp <= 0);
}

bool Character::selectability() {
	return false;
}

bool Character::attackability() {
	return true;
}

bool Character::usability() {
	return false;
}

char Character::retRace() {
	return race;
}

int Character::retX(){
	return x;
}

int Character::retY(){
	return y;
}

Character::~Character() {}
